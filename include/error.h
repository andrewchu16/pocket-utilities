#pragma once 
#include <iostream>

namespace putil {
    void report(std::string msg, int error_code);
    void report(std::string location, std::string msg, int error_code);
    void warn(std::string msg);
    void warn(std::string location, std::string msg);
}