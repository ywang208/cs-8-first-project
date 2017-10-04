#ifndef MEMBERSLIST_H
#define MEMBERSLIST_H
#include <iostream>
#include <sstream>

// struct nodes of Members templated
template<typename M>
struct Members
{
    M data;
    Members* next;
    Members* prev;
    Members(M data) : data(data), next(NULL), prev(NULL) {}

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
    // Constructor
    MembersList();
    // Copy Constructor
    MembersList(const MembersList& list);
    // Assignment Operator
    MembersList& operator=(const MembersList& list);
    // Destructor
    ~MembersList();
    // push_back
    void push_back(const M& value);
    // select_sort
    void select_sort();
    // isEmpty
    bool isEmpty()const;
    // output stringstream
    std::string output_linkedlist();
    // return true if member is in the list
    bool find_member(const M& value);
    // find position of member
    size_t find_position_member(const M& value);


    // remove member needs to be fixed
    bool remove_member(const M& value);
    // not in use
    void push_front(const M& value);
    void pop_front() noexcept(false);
    void pop_back() noexcept(false);
    size_t members_size() const;

};

template<typename M>
MembersList<M>::MembersList() :
    head(NULL),
    tail(NULL) {}

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
        throw ("ERROR");
}

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
        throw ("ERROR");
}

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

template<typename M>
bool MembersList<M>::isEmpty() const
{
    return head == NULL;
}

template<typename M>
bool MembersList<M>::remove_member(const M& value)
{
    if(head == NULL)
        return false;
    else
    {
        Members<M> *temp = head;
        while(temp->data != value)
            temp = temp->next;
        if(temp != NULL)
        {
            if(temp->prev == NULL)
            {
                pop_front();
                return true;
            }
            else if(temp->next == NULL)
            {
                pop_back();
                return true;
            }
            else
            {
                Members<M> *prevTemp = temp->prev;
                prevTemp->next = temp->next;
                temp->next->prev = prevTemp;
                delete temp;
                temp = NULL;
                return true;
            }
        }
        else
            return false;
    }
}// not working.. fixed code

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

template<typename M>
size_t MembersList<M>::members_size() const
{
    return count_helper(head);
}

template<typename M>
size_t MembersList<M>::count_helper(Members<M> * mPtr) const
{
    if(mPtr == NULL)
        return 0;
    else
        return 1 + count_helper(mPtr->prev);
}

#endif // MEMBERSLIST_H
