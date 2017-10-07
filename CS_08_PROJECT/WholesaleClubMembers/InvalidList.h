#ifndef INVALIDLIST_H
#define INVALIDLIST_H
#include <iostream>
#include <sstream>

class InvalidList
{
public:
    std::string invalid_error;
    InvalidList(std::string msg) : invalid_error(msg){}
    std::string print_error_msg() const
    {
        std::stringstream ss_error_out;
        ss_error_out << invalid_error;
        return ss_error_out.str();
    }
};


#endif // INVALIDLIST_H
