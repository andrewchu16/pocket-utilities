#include "p-utils-lib.h"

#include <iostream>
#include <map>

using namespace std;

map<string, int> flags;

#define T_DEFAULT 0

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
        case T_DEFAULT:
            break;
    }
}

int p_utils(string command)
{
    
}