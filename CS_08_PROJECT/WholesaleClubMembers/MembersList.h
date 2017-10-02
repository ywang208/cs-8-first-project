#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <sstream>

template<typename M>
struct Members
{
    M data;
    Members* next;
    Members* prev;
    Members(M data) : data(data), next(NULL), prev(NULL) {}
};

template<typename M>
class MembersList
{
    Members<M>* head;
    Members<M>* tail;
    size_t count_helper(Members<M>* mPtr) const;
    void display_helper(Members<M>* tmp) const;
public:
    MembersList();
    MembersList(const MembersList& list);
    MembersList& operator=(const MembersList& list);
    ~MembersList();
    std::string display();
    void push_back(const M& value);
    void push_front(const M& value);
    void pop_front() noexcept(false);
    void pop_back() noexcept(false);
    void select_sort();
    bool remove_member(M value);
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
    Members<M>* newPtr = NULL;
    Members<M>* tPtr = NULL;
    Members<M>* headPtr;
    headPtr = list.head;
    while(headPtr != NULL)
    {
        push_back(headPtr->data);
        headPtr = headPtr->next;
    }

    //    if(headPtr != NULL)
    //    {
    //        newPtr = new Members<M>(headPtr->data);
    //        head = tail = newPtr;
    //        headPtr = headPtr->next;
    //        while(headPtr != NULL)
    //        {
    //            newPtr = new Members<M>(headPtr->data);
    //            tail->next = newPtr;
    //            tail = newPtr;
    //            headPtr = headPtr->next;
    //        }
    //    }
    //    else
    //        head = tail = NULL;
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



    //    headPtr = head;
    //    while(headPtr != NULL)
    //    {
    //        head = head->next;
    //        delete headPtr;
    //        headPtr = head;
    //    }
    //    headPtr = list.head;
    //    if(headPtr != NULL)
    //    {
    //        newPtr = new Members<M>(headPtr->data);
    //        head = tail = newPtr;
    //        headPtr = headPtr->next;
    //    }
    //    else
    //        head = tail = NULL;
    //    while(headPtr != NULL)
    //    {
    //        newPtr = new Members<M>(headPtr->data);
    //        tail->next = newPtr;
    //        tail = newPtr;
    //        headPtr = headPtr->next;
    //    }
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
std::string MembersList<M>::display()
{
    std::stringstream out_sss;
    Members<M>* temp = head;
    while(isEmpty())
    {
        out_sss << temp->data;
        if(temp->next != NULL)
            out_sss << " ";
        temp = temp->next;
    }
    return out_sss.str();
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


    //    if(isEmpty())
    //        head = tail = newPtr;
    //    else
    //    {
    //        tail->next = newPtr;
    //        tail = newPtr;
    //    }
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
        head->prev = NULL;
        head->next = NULL;
        tail = head;
    }

    //    if(isEmpty())
    //        head = tail = newPtr;
    //    else
    //    {
    //        head->prev = newPtr;
    //        newPtr->next = head;
    //        head = newPtr;
    //    }
}

template<typename M>
void MembersList<M>::pop_front() noexcept(false)
{
    if(isEmpty())
    {
        if(head->next == NULL)
        {
            delete head;
            head = NULL;
            tail = NULL;
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
    //    if(isEmpty())
    //        throw("Cannot use pop_front");
    //    else
    //    {
    //        Members<M> *headPtr = head;
    //        head = head->next;
    //        delete headPtr;
    //    }
}

template<typename M>
void MembersList<M>::pop_back() noexcept(false)
{
    if(tail != NULL)
    {
        if(tail->prev == NULL)
        {
            delete tail;
            head = NULL;
            tail = NULL;
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
}// this is O(n^2). try to find O(n log n) or better

template<typename M>
bool MembersList<M>::isEmpty() const
{
    return head == NULL;
}

template<typename M>
bool MembersList<M>::remove_member(M value)
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
