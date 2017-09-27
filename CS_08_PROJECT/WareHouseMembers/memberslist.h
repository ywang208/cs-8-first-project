#ifndef MEMBERSLIST_H
#define MEMBERSLIST_H
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
    Members<M> * head, * tail;
public:

    MembersList();
    MembersList(const MembersList& list);
    MembersList & operator =(const MembersList& list);
    ~MembersList();
    void push_back(const M& value);
    void push_front(const M& value);
    void pop_front() noexcept(false);
    void select_sort();
    void remove_duplicates();
    bool isEmpty()const;
    std::string output_linkedlist();
};

template<typename M>
MembersList<M>::MembersList() : head(NULL), tail(NULL) {}

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
MembersList<M> & MembersList<M>::operator = (const MembersList& list)
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
    Members<M> *headPtr;
    headPtr = head;

    while(headPtr != NULL)
    {
        head = head->next;
        delete headPtr;
        headPtr = head;
    }
    tail = NULL;
}

template<typename M>
void MembersList<M>::push_back(const M &value)
{
    Members<M> *newPtr;
    newPtr = new Members<M>(value);

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
    Members<M> *newPtr;
    newPtr = new Members<M>(value);

    if(isEmpty())
        head = tail = newPtr;
    else
    {
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
        Members<M> *headPtr;
        headPtr = head;
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
}

template<typename M>
void MembersList<M>::remove_duplicates()
{
    Members<M> * headPtr,
            * nextPtr,
            * deletePtr;

    headPtr = head;

    while(headPtr != NULL)
    {
        nextPtr = headPtr;
        while(nextPtr->next != NULL)
        {
            if(nextPtr->next->data == headPtr->data)
            {
                deletePtr = nextPtr->next;
                nextPtr->next = deletePtr->next;
                delete deletePtr;
            }
            else
                nextPtr = nextPtr->next;
        }
        tail = headPtr;
        headPtr = headPtr->next;
    }
}

template<typename M>
bool MembersList<M>::isEmpty() const
{
    return head == NULL;
}

template<typename M>
std::string MembersList<M>::output_linkedlist()
{
    std::stringstream out_ss;
    out_ss << "{ ";
    for(Members<M> * i = head; i != NULL; i = i->next)
    {
        out_ss << i->data;
        if(i->next != NULL)
            out_ss << ", ";
    }
    out_ss << " }";
    return out_ss.str();
}

/*
class Date
{
public:
    Date();
    Date(unsigned m, unsigned d, unsigned y);
    Date(const std::string &mn, unsigned d, unsigned y);
    void printNumeric() const;
    void printAlpha() const;
private:
    size_t month;
    size_t day;
    size_t year;
    std::string monthName;
    bool isLeap(unsigned y) const;
    unsigned daysPerMonth(unsigned m, unsigned y) const;
    std::string name(unsigned m) const;
    unsigned number(const std::string &mn) const;
};

Date::Date():month(1),day(1),year(2000)
{
    name(month);
}

Date::Date(unsigned m, unsigned d, unsigned y)
{
    if(d > daysPerMonth(m, y))
    {
        month = m >= 1 && m <= 12 ? m : m < 1 ? 1 : m < 12 ? m : 12;
        day = d >= 1 && d <= daysPerMonth(month, y) ? d : d < 1
                                                      ? 1 : d < daysPerMonth(month, y) ? d : daysPerMonth(month, y);
        year = y;
        std::cout << "Invalid date values. Date corrected to: " << month << "/"
                  << day << "/" << year << std::endl;
    }
    else
    {
        month = m >= 1 && m <= 12 ? m : m < 1 ? 1 : m < 12 ? m : 12;
        day = d >= 1 && d <= daysPerMonth(month, y) ? d : d < 1
                                                      ? 1 : d < daysPerMonth(month, y) ? d : daysPerMonth(month, y);
        year = y;
    }
}

Date::Date(const std::string &mn, unsigned d, unsigned y)
{
    const unsigned SIZE = 12;
    const std::string months[SIZE] = {"January","February","March",
                                      "April","May","June",
                                      "July","August","September",
                                      "October","Novermber","December"};

    if(d > daysPerMonth(number(mn), y) || d == 0)
    {
        month = number(mn);
        day = d >= 1 && d <= daysPerMonth(month, y) ? d : d < 1
                                                      ? 1 : d < daysPerMonth(month, y) ? d : daysPerMonth(month, y);
        year = y;
        std::cout << "Invalid date values: Date corrected to " << month << "/"
                  << day << "/" << year << "." << std::endl;
    }
    else if(mn == months[number(mn) - 1])
    {
        month = number(mn);
        day = d >= 1 && d <= daysPerMonth(month, y) ? d : d < 1
                                                      ? 1 : d < daysPerMonth(month, y) ? d : daysPerMonth(month, y);
        year = y;
    }
    else
    {
        std::string temp = mn;
        temp[0] = mn[0] + ('A' - 'a');
        monthName = name(number(temp));
        month = number(monthName);
        day = d >= 1 && d <= daysPerMonth(month, y) ? d : d < 1
                                                      ? 1 : d < daysPerMonth(month, y) ? d : daysPerMonth(month, y);
        year = y;
    }
}

void Date::printNumeric() const
{
    std::cout << month << "/" << day << "/" << year;
}

void Date::printAlpha() const
{
    std::cout << name(month) << " " << day << ", " << year;
}

bool Date::isLeap(unsigned y) const
{
    return ((y % 400) == 0 || ( (y % 4) == 0 && (y % 100) != 0 ));
}

unsigned Date::daysPerMonth(unsigned m, unsigned y) const
{
    const unsigned SIZE = 12;
    const unsigned days[SIZE] = {31,28,31,30,31,30,31,31,30,31,30,31};
    return isLeap(y) && m == 2 ? 29 : days[m - 1];
}

std::string Date::name(unsigned m) const
{
    const size_t SIZE = 12;
    const std::string months[SIZE] = {"January","February","March",
                                      "April","May","June",
                                      "July","August","September",
                                      "October","Novermber","December"};
    return months[m - 1];
}

unsigned Date::number(const std::string &mn) const
{
    const size_t SIZE = 12;
    const std::string months[SIZE] = {"January","February","March",
                                      "April", "May","June",
                                      "July", "August", "September",
                                      "October","Novermber", "December"};
    size_t month_number = 0;
    bool found = false;

    for(size_t i = 0; i < SIZE; ++i)
    {
        if(mn == months[i])
        {
            month_number = i;
            found = true;
        }
    }
    return month_number + 1;
}

*/
#endif // MEMBERSLIST_H
