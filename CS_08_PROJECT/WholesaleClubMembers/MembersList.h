#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <sstream>

template<typename M>
struct Members
{
    M data;
    Members *next;
    Members(M data) : data(data), next(NULL) {}
};

template<typename M>
class MembersList
{
    Members<M>* head;
    Members<M>* tail;
    size_t count_helper(Members<M> * mPtr) const;
public:
    MembersList();
    MembersList(const MembersList& list);
    MembersList& operator=(const MembersList& list);
    ~MembersList();
    void push_back(const M& value);
    void push_front(const M& value);
    void pop_front() noexcept(false);
    void select_sort();
    bool remove_member(const M& value);
    bool isEmpty()const;
    std::string output_linkedlist();
    size_t members_size() const;
    bool find_member(const M& value);
};

template<typename M>
MembersList<M>::MembersList() :
    head(NULL),
    tail(NULL) {}

template<typename M>
MembersList<M>::MembersList(const MembersList& list)
{
    Members<M> *newPtr = NULL;
    Members<M> *headPtr;
    headPtr = list.head;
    if(headPtr != NULL)
    {
        newPtr = new Members<M>(headPtr->data);
        head = tail = newPtr;
        headPtr = headPtr->next;
        while(headPtr != NULL)
        {
            newPtr = new Members<M>(headPtr->data);
            tail->next = newPtr;
            tail = newPtr;
            headPtr = headPtr->next;
        }
    }
    else
        head = tail = NULL;
}

template<typename M>
MembersList<M>& MembersList<M>::operator=(const MembersList& list)
{
    Members<M> *headPtr;
    Members<M> *newPtr;
    headPtr = head;
    while(headPtr != NULL)
    {
        head = head->next;
        delete headPtr;
        headPtr = head;
    }
    headPtr = list.head;
    if(headPtr != NULL)
    {
        newPtr = new Members<M>(headPtr->data);
        head = tail = newPtr;
        headPtr = headPtr->next;
    }
    else
        head = tail = NULL;
    while(headPtr != NULL)
    {
        newPtr = new Members<M>(headPtr->data);
        tail->next = newPtr;
        tail = newPtr;
        headPtr = headPtr->next;
    }
    return *this;
}

template<typename M>
MembersList<M>::~MembersList()
{
    Members<M>* headPtr = head;
    Members<M>* delPtr;
    while(headPtr != NULL)
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
    Members<M> *newPtr = new Members<M>(value);
    if(isEmpty())
        head = tail = newPtr;
    else
    {
        tail->next = newPtr;
        tail = newPtr;
    }
}

template<typename M>
void MembersList<M>::push_front(const M &value)
{
    Members<M> *newPtr = new Members<M>(value);
    if(isEmpty())
        head = tail = newPtr;
    else
    {
        head->prev = newPtr;
        newPtr->next = head;
        head = newPtr;
    }
}

template<typename M>
void MembersList<M>::pop_front() noexcept(false)
{
    if(isEmpty())
        throw("Cannot use pop_front");
    else
    {
        Members<M> *headPtr = head;
        head = head->next;
        delete headPtr;
    }
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
}// this is O(n^2). try to find O(n log n) or better

template<typename M>
bool MembersList<M>::isEmpty() const
{
    return head == NULL;
}

template<typename M>
bool MembersList<M>::remove_member(const M& value)
{
    MembersList<M>* newPtr;
    newPtr = head;
    MembersList<M>* nextPtr, * delPtr;

    while(newPtr != nullptr)
    {
        nextPtr = newPtr;
        while(nextPtr->next != nullptr)
        {
            if(newPtr->next->data == value->data)
            {
                delPtr = nextPtr->next;
                nextPtr->next = delPtr->next;
                delete delPtr;
            }
            else
                nextPtr = nextPtr->next;
        }
        tail = newPtr;
        newPtr = newPtr->next;

    }
    return false;
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
        return 1 + count_helper(mPtr->next);
}


#endif // LINKEDLIST_H
