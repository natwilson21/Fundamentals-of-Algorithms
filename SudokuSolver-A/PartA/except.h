#ifndef EXCEPT_H
#define EXCEPT_H

#include <stdexcept>
#include <string>

class rangeError : public std::out_of_range 
{
public:
    rangeError(const std::string& what_arg) : std::out_of_range(what_arg) {}
};

#endif  // EXCEPT_H
