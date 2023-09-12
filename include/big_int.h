#pragma once
#include <deque>
#include <iostream>
#include <fstream>
#include <cctype>

namespace putil {
    class big_int 
    {
        public:
            big_int(const std::string &str_num);
            big_int(const char *cstr_num);
            big_int(const int64_t num);

            void fprint(std::ostream &fout);

            std::string to_str();
            char *to_cstr();

            std::size_t num_digits();
            bool is_positive();

            // returns the nth digit from the right
            int8_t digit_at(const std::size_t n);

            void add(big_int &b_num);
            void add(const std::string &str_num);
            void add(const char *cstr_num);
            void add(int64_t num);

            void sub(big_int &b_num);
            void sub(const std::string &str_num);
            void sub(const char *cstr_num);
            void sub(const int64_t num);
        private:
            bool _is_positive;
            std::deque<uint8_t> _arr; // uint8_t to minimize space

            bool _check_valid_str_num(const std::string &str);
            bool _check_valid_cstr_num(const char *cstr);

            void _add(big_int &b_num);
            void _sub(big_int &b_num);
    };
}