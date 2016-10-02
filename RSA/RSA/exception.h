#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <iostream>
#include <string>

struct Exception : public std::exception
{
    std::string s;
    Exception(std::string ss) : s(ss) {}
    ~Exception() throw () {} // Updated
    const char* message() const throw() { return s.c_str(); }
};

#endif
