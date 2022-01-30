#include "p-utils-lib.h"

int main(int argc, char *argv[]) 
{
    putil::parse_cmd(argc - 1, argv + 1);
    std::cout << "hello from main.cpp" << std::endl;
}
