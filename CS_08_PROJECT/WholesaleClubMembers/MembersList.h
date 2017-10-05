#ifndef MEMBERSLIST_H
#define MEMBERSLIST_H
#include "InvalidMembers.h"

// struct nodes of Members templated
template<typename M>
struct Members
{
    M data;
    Members* next;
    Members* prev;
    Members(M data) :
        data(data),
        next(NULL),
        prev(NULL) {}
};

// class MembersList templated
template<typename M>
class MembersList
{
    // Head and Tail pointers
    Members<M>* head;
    Members<M>* tail;
    // Counter
    size_t count_helper(Members<M>* mPtr) const;
public:
    MembersList();                                          // Constructor
    MembersList(const MembersList& list);                   // Copy Constructor
    MembersList& operator=(const MembersList& list);        // Assignment Operator
    ~MembersList();                                         // Destructor
    Members<M>* return_member(size_t pos) const;            // returns members data type with its position given
    size_t members_size() const;                            // returns size of list
    size_t find_position_member(const M& value);            // find position of member
    bool isEmpty()const;                                    // isEmpty
    bool find_member(const M& value);                       // return true if member is in the list
    bool remove_member(const M& value);                     // remove member
    void select_sort();                                     // select_sort
    void push_back(const M& value);                         // push_back
    void push_front(const M& value);                        // push_front
    void pop_front() noexcept(false);                       // pop_front
    void pop_back() noexcept(false);                        // pop_back
    std::string output_linkedlist();                        // output stringstream
};

// Constructor
template<typename M>
MembersList<M>::MembersList() :
    head(NULL),
    tail(NULL) {}

// Copy Constructor
template<typename M>
MembersList<M>::MembersList(const MembersList& list)
{
    Members<M>* newPtr = NULL;
    Members<M>* tPtr = NULL;
    Members<M>* headPtr;
    headPtr = list.head;
    while(headPtr != NULL)
    {
        push_back(headPtr->data);
        headPtr = headPtr->next;
    }
}

// Assignment Operator
template<typename M>
MembersList<M>& MembersList<M>::operator=(const MembersList& list)
{
    Members<M> *headPtr = list.head;
    if(head != NULL)
    {
        Members<M>* temp = head;
        while(temp != NULL)
        {
            head = head->next;
            delete temp;
            head = temp;
        }
        tail = NULL;
        while (headPtr != NULL)
        {
            push_back(headPtr->data);
            headPtr = headPtr->next;
        }
    }
    else
    {
        while(headPtr != NULL)
        {
            push_back(headPtr->data);
            headPtr = headPtr->next;
        }
    }
    return *this;
}

// Destructor
template<typename M>
MembersList<M>::~MembersList()
{
    Members<M>* headPtr = head;
    Members<M>* delPtr;
    while(isEmpty())
    {
        delPtr = headPtr;
        delete headPtr;
        headPtr = headPtr->next;
    }
    tail = NULL;
}

// returns members data type with its position given
template<typename M>
Members<M>* MembersList<M>::return_member(size_t pos) const
{
    Members<M>* tmp = head;
    for(size_t i = 0; i < pos - 1; ++i)
        tmp = tmp->next;
    return tmp;
}

// returns size of list
template<typename M>
size_t MembersList<M>::members_size() const
{
    return count_helper(head);
}

// find position of member
template<typename M>
size_t MembersList<M>::find_position_member(const M& value)
{
    size_t index = 0;
    for(Members<M>* i = head; i != NULL; i = i->next)
    {
        if(i->data == value)
            index = count_helper(i);
    }
    return index;
}

// isEmpty
template<typename M>
bool MembersList<M>::isEmpty() const
{
    return head == NULL;
}

// return true if member is in the list
template<typename M>
bool MembersList<M>::find_member(const M& value)
{
    for(Members<M>* i = head; i != NULL; i = i->next)
    {
        if(i->data == value)
            return true;
    }
    return false;
}

// remove member
template<typename M>
bool MembersList<M>::remove_member(const M& value)
{
    Members<M>* index = head;
    for(; index != NULL; index = index->next)
    {
        if(index->data == value)
        {
            if(index->prev == NULL)
                head = index->next;
            else if(index->next == NULL)
                index->prev->next = NULL;
            else
            {
                index->prev->next = index->next;
                index->next->prev = index->prev;
            }
            delete index;
            return true;
        }
    }
    return false;
}

// select sort
template<typename M>
void MembersList<M>::select_sort()
{
    for(Members<M> * i = head; i != NULL; i = i->next)
    {
        for(Members<M> * j = i->next; j != NULL; j = j->next)
        {
            if(j->data < i->data)
            {
                M temp = j->data;
                j->data = i->data;
                i->data = temp;
            }
        }
    }
}

// push_back
template<typename M>
void MembersList<M>::push_back(const M &value)
{
    if(tail != NULL)
    {
        Members<M> *newPtr = new Members<M>(value);
        newPtr->prev = tail;
        tail->next = newPtr;
        tail = newPtr;
        tail->next = NULL;
    }
    else
    {
        Members<M> *newPtr = new Members<M>(value);
        tail = newPtr;
        tail->prev = NULL;
        head = tail;
        tail->next = NULL;
    }
}

// push_front
template<typename M>
void MembersList<M>::push_front(const M &value)
{
    if(isEmpty())
    {
        Members<M> *newPtr = new Members<M>(value);
        newPtr->next = head;
        head->prev = newPtr;
        head = newPtr;
        head->prev = NULL;
    }
    else
    {
        Members<M> *newPtr = new Members<M>(value);
        head = newPtr;
        head->prev = head->next = NULL;
        tail = head;
    }
}

// pop_front
template<typename M>
void MembersList<M>::pop_front() noexcept(false)
{
    if(isEmpty())
    {
        if(head->next == NULL)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            Members<M>* temp = head->next;
            delete head;
            head = temp;
            temp->prev = NULL;
        }
    }
    else
        throw InvalidMembers("ERROR");
}

// pop_back
template<typename M>
void MembersList<M>::pop_back() noexcept(false)
{
    if(tail != NULL)
    {
        if(tail->prev == NULL)
        {
            delete tail;
            head = tail = NULL;
        }
        else
        {
            Members<M> *temp = tail->prev;
            delete tail;
            tail = temp;
            tail->next = NULL;
        }
    }
    else
        throw InvalidMembers("ERROR");
}

// output stringstream
template<typename M>
std::string MembersList<M>::output_linkedlist()
{
    std::stringstream out_ss;
    out_ss << "\n";
    for(Members<M> * i = head; i != NULL; i = i->next)
    {
        out_ss << i->data;
        if(i->next != NULL)
            out_ss << "\n";
    }
    out_ss << "\n";
    return out_ss.str();
}

// helper function for counter
template<typename M>
size_t MembersList<M>::count_helper(Members<M> * mPtr) const
{
    if(mPtr == NULL)
        return 0;
    else
        return 1 + count_helper(mPtr->prev);
}

#endif // MEMBERSLIST_H
