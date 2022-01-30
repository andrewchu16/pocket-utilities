#pragma once

#include <iostream>
#include <map>

namespace putil {
    void parse_cmd(const int argc, char *argv[]);
    void help_topic(const int &topic);
    int p_utils(std::string command);
}