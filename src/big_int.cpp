// #pragma once

#include <string>
#include <deque>
#include <cassert>
#include <cstdio>

#include <iostream>

#define _stringify(name) #name

using namespace std;

class big_int {
    private:
        int length;
        bool positive;

        deque<char>_num; 
        string str_num;
        char *chr_num;

        bool str_num_computed = false;

        bool __check_valid(const string &, const bool, const int);
        void __carry(int, int);
    public:
        big_int(const string &);
        void debug();

        string to_string();
        char *to_chars();
        void add(const string &);
};

big_int::big_int(const string &num) 
{
    positive = (num[0] == '-') ? false : true;

    length = num.size() - !positive; // subtract from length if number is positive

    _num.resize(length);

    if (__check_valid(num, positive, length)) 
    {
        for (int i = 0; i < length; i++)
        {
            _num[i] = num[i + !positive];
        }
    }

    str_num_computed = false;
}


void big_int::debug()
{
    printf("big_int(\"");

    for (auto &it : _num)
    {
        printf("%c", it);
    }

    assert(length == _num.size() - !positive);
    printf("\"). Length: %i.\n", length);
}


string big_int::to_string() 
{
    if (!str_num_computed) {
        str_num.resize(length + !positive);

        str_num[0] = (positive) ? str_num[0] : '-';
        
        for (int i = 0; i < length; i++) 
        {
            str_num[i + !positive] = _num[i];
        }
        str_num_computed = true;
    }
    return str_num;
}


void big_int::add(const string &num)
{
    bool num_positive = (num[0] == '-') ? false : true;
    int num_length = num.size() - !num_positive;

    __check_valid(num, num_positive, num_length);

    int multip = num_positive - !num_positive; 
    // 0 - !0 = -1
    // 1 - !1 = 1

    int offset = num.size() - length - !positive;

    for (int i = length - 1; i + offset >= 0; i--) 
    {
        // cout << i << " " << i + offset << endl;
        int temp = (num[i + offset] - '0') * multip;
        __carry(i, temp);
    }

    str_num_computed = false;
}


bool big_int::__check_valid(const string &num, const bool num_positive, const int num_length) 
{   
    // ensure valid number length
    assert(num_length > 0);
    for (int i = !num_positive; i < num_length + !num_positive; i++)
    {
        // check if each digit is valid
        if('0' > num[i] || num[i] > '9') 
        {
            printf("invalid digit at num.%i: '%c'.\n\nConstructor failed.\n", i, num[i]);
        }
        assert('0' <= num[i] && num[i] <= '9');
    }
    return true;
}


/*
 * @param digit the digit to be carried onto
 * @param value the value (as an int) being carried
*/
void big_int::__carry(int digit, int value) 
{
    // if needed to carry past the highest digit place
    if (digit < 0) 
    {
        _num.push_front('0');
        digit = 0;
        length++;
    }

    int temp = value + _num[digit] - '0';

    _num[digit] = temp % 10 + '0';

    // carry again if necessary
    if (temp > 9) 
    {
        __carry(digit - 1, temp / 10);
    }
}


int main(void) 
{
    big_int a("7");
    a.debug();

    // does not work
    a.add("-17");
    a.debug();

}