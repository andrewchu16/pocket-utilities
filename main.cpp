#include <iostream>
#include <map>
#include "p-utils-lib.h"

using namespace std;

map<string, int> flags;

// help topics
enum topics {
    T_DEFAULT,
    T_SIMUL,
    T_CRYPTO,
    T_CALC
};

void parse_cmd(const int argc, char *argv[]);
void help_topic(const int &topic);
int p_utils(string command);

int main(int argc, char *argv[]) 
{
    parse_cmd(argc - 1, argv + 1);
}

void parse_cmd(const int ac, char *av[]) 
{

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

int p_utils(string command)
{
    
}