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
class LinkedList
{
    Members<M>* head;
    Members<M>* tail;
public:
    LinkedList();

};

#endif // LINKEDLIST_H
