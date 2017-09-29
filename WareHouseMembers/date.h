#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <sstream>

template <typename M>
class Date
{
public:
    Date();
    Date(size_t m, size_t d, size_t y);
    Date(const std::string& mn, size_t d, size_t y);
    std::string printNumeric();
    void printAlpha() const;
private:
    size_t month;
    size_t day;
    size_t year;
    std::string monthName;
    bool isLeap(size_t y) const;
    size_t daysPerMonth(size_t m, size_t y) const;
    std::string name(size_t m) const;
    size_t number(const std::string& mn) const;
};

template <typename M>
Date<M>::Date()
{
    month = 1;
    day = 1;
    year = 2000;
    //monthName(1);
}

template <typename M>
Date<M>::Date::Date(size_t m, size_t d, size_t y)
{
    //std::stringstream out_ss;
    if(d > daysPerMonth(m, y))
    {
        month = m >= 1 && m <= 12 ? m : m < 1 ? 1 : m < 12 ? m : 12;
        day = d >= 1 && d <= daysPerMonth(month, y) ? d : d < 1
        ? 1 : d < daysPerMonth(month, y) ? d : daysPerMonth(month, y);
        year = y;
        std::cout << "Invalid date values. Date corrected to: " << month << "/"
        << day << "/" << year << "\n";
    }
    else
    {
        month = m >= 1 && m <= 12 ? m : m < 1 ? 1 : m < 12 ? m : 12;
        day = d >= 1 && d <= daysPerMonth(month, y) ? d : d < 1
        ? 1 : d < daysPerMonth(month, y) ? d : daysPerMonth(month, y);
        year = y;
    }
}

template <typename M>
Date<M>::Date(const std::string& mn, size_t d, size_t y)
{
    const size_t SIZE = 12;
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

template <typename M>
std::string Date<M>::Date::printNumeric()
{
    std::stringstream out_ss;
    out_ss << month << "/" << day << "/" << year;
    return out_ss.str();
}

template <typename M>
void Date<M>::Date::printAlpha() const
{
    std::cout << name(month) << " " << day << ", " << year;
}

template <typename M>
bool Date<M>::Date::isLeap(size_t y) const
{
    return ((y % 400) == 0 || ( (y % 4) == 0 && (y % 100) != 0 ));
}

template <typename M>
size_t Date<M>::Date::daysPerMonth(size_t m, size_t y) const
{
    const unsigned SIZE = 12;
    const unsigned days[SIZE] = {31,28,31,30,31,30,31,31,30,31,30,31};
    return isLeap(y) && m == 2 ? 29 : days[m - 1];
}

template <typename M>
std::string Date<M>::name(size_t m) const
{
    const unsigned SIZE = 12;
    const std::string months[SIZE] = {"January","February","March",
                                 "April","May","June",
                                 "July","August","September",
                                 "October","Novermber","December"};
    return months[m - 1];
}

template <typename M>
size_t Date<M>::number(const std::string &mn) const
{
    const unsigned SIZE = 12;
    const std::string months[SIZE] = {"January","February","March",
        "April", "May","June",
        "July", "August", "September",
        "October","Novermber", "December"};
    unsigned month_number = 0;
    bool found = false;

    for(unsigned i = 0; i < SIZE; ++i)
    {
        if(mn == months[i])
        {
            month_number = i;
            found = true;
        }
    }
    return month_number + 1;
}
#endif // DATE_H
