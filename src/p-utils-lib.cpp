#include "p-utils-lib.h"

namespace putil {
std::map<std::string, int> flags;

// help topics
enum topics {
    T_DEFAULT,
    T_SIMUL,
    T_CRYPTO,
    T_CALC
};

void parse_cmd(const int ac, char *av[]) 
{
    return;
}

// display the help information for a topic
void help_topic(const int &topic) 
{
    switch (topic) 
    {
        // display general help
        case 0:
            break;
        // invalid topic
        default:
            break;
    }
}

int p_utils(std::string command)
{
    return 0;
}
}