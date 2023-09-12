#include "p-utils-lib.h"
#include "big_int.h"

int main(int argc, char *argv[]) 
{
    // putil::parse_cmd(argc - 1, argv + 1);
    std::cout << "hello from main.cpp" << std::endl;

    putil::big_int b = putil::big_int("25");
    
    std::cout << b.to_str() << std::endl;

    b.add(26);
    std::cout << b.to_str() << std::endl;

}
