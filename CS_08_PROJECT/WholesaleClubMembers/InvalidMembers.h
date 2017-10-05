#ifndef INVALIDMEMBERS_H
#define INVALIDMEMBERS_H
#include <iostream>
#include <sstream>

class InvalidMembers
{
public:
    std::string invalid_error;
    InvalidMembers(std::string msg) : invalid_error(msg){}
    std::string print_error_msg() const
    {
        std::stringstream ss_error_out;
        ss_error_out << invalid_error;
        return ss_error_out.str();
    }
};

#endif // INVALIDMEMBERS_H
