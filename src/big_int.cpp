#include "big_int.h"
#include "common.h"
#include "error.h"

namespace putil {
    big_int::big_int(const std::string &str_num) {
        if (!_check_valid_str_num(str_num)) {
            report("big_int", "initialization string invalid.\n", 1);
        } 

        _is_positive = (str_num[0] != '-');

        // Offset negative sign and any leading zeros. E.g., "000123456".
        std::size_t ofs = (_is_positive ? 0 : 1);
        while (ofs < str_num.size() && str_num[ofs] == '0') ofs++;
        //  A whole string of leading zeros is equivalent to "0"
        if (ofs == str_num.size()) ofs--;

        for (std::size_t i = ofs; i < str_num.size(); i++) {
            _arr.push_back(str_num[i] - '0');
        }
    }
    
    big_int::big_int(const char *cstr_num) {
        if (!_check_valid_cstr_num(cstr_num)) {
            report("big_int", "initialization c-string invalid.\n", 1);
        }

        _is_positive = (cstr_num[0] != '-');

        // Offset negative sign and any leading zeros. E.g., "000123456".
        std::size_t ofs = (_is_positive ? 0 : 1);
        while (cstr_num[ofs] != '\0' && cstr_num[ofs] == '0') ofs++;
        //  A whole string of leading zeros is equivalent to "0"
        if (cstr_num[ofs] == '\0') ofs--;

        for (std::size_t i = ofs; cstr_num[i] != '\0' ; i++) {
            _arr.push_back(cstr_num[i] - '0');
        }
    }

    big_int::big_int(int64_t num) {
        _is_positive = (num >= 0);

        if (!_is_positive) num = -num;

        while (num) {
            int8_t digit = num % 10;
            _arr.push_front(digit);
            num /= 10;
        }
    }

    std::string big_int::to_str() {
        std::string str_num;
        str_num.reserve(_arr.size() + !_is_positive);

        if (!_is_positive) str_num += "-";

        for (uint8_t &digit : _arr) {
            str_num += static_cast<char>(digit + '0');
        }

        return str_num;
    }

    // NOTE: allocates with 'new' operator, not malloc.
    char *big_int::to_cstr() {
        std::size_t ofs = !_is_positive;
        std::size_t length = _arr.size() + ofs;
        char *cstr_num = new char[length + 1];

        if (!_is_positive) cstr_num[0] = '-';

        for (std::size_t i = 0; i < _arr.size(); i++) {
            cstr_num[i + ofs] = static_cast<char>(_arr[i] + '0');
        }
        cstr_num[length] = '\0';

        return cstr_num;
    }

    std::size_t big_int::num_digits() {
        return _arr.size();
    }

    bool big_int::is_positive() {
        return _is_positive;
    }

    int8_t big_int::digit_at(const std::size_t n) {
        // deque object should handle errors
        return _arr[n];
    }

    // observation: 
    // if the signs look the same, it looks like adding
    // if the signs look different, it looks like subtracting
    void big_int::add(big_int &b_num) {
        if (b_num.is_positive() == _is_positive) _add(b_num);
        else sub(b_num);
    }

    void big_int::add(const std::string &str_num) {
        big_int b_num(str_num);
        add(b_num);
    }

    void big_int::add(const char *cstr_num) {
        big_int b_num(cstr_num);
        add(b_num);
    }

    void big_int::add(int64_t num) {
        big_int b_num(num);
        add(b_num);
    }

    // if the signs look the same, it looks like subtracting
    // if the signs look different, it looks like adding
    void big_int::sub(big_int &b_num) {
        if (b_num.is_positive() && _is_positive) _sub(b_num);
        else _add(b_num);
    }

    void big_int::sub(const std::string &str_num) {
        big_int b_num(str_num);
        sub(b_num);
    }

    void big_int::sub(const char *cstr_num) {
        big_int b_num(cstr_num);
        sub(b_num);
    }

    void big_int::sub(const int64_t num) {
        big_int b_num(num);
        sub(b_num);
    }

    bool big_int::_check_valid_str_num(const std::string &str) {
        if (str.size() == 0) return true; 

        for (std::size_t i = 0; i < str.size(); i++) {
            if (!isdigit(str[i])) return false;
        }

        // string "-" is invalid.
        if (str[0] == '-' && str.size() == 1) return false;
        return true;
    }

    bool big_int::_check_valid_cstr_num(const char *cstr) {
        // Zero-length c-str allowed but not a NULL pointer.
        if (cstr == NULL) {
            warn("big_int", "c-string null.\n"); 
            return false;
        }

        if (cstr[0] == '\0') return true;

        for (std::size_t i = 0; cstr[i] != '\0'; i++) {
            if (!isdigit(cstr[i])) {
                warn("big_int", "c-string invalid digit.\n");
                return false;
            }
        }

        // string "-" is invalid.
        if (cstr[0] == '-' && cstr[1] == '\0') {
            warn("big_int", "c-string cannot be \"-\"\n.");
            return false;
        }
        return true;
    }

    void big_int::_add(big_int &b_num) {
        int8_t carry = 0, new_digit = 0;
        std::size_t ofs = num_digits() - 1;

        for (std::size_t ind = 0; ind < b_num.num_digits(); ind++) {
            new_digit = (b_num.digit_at(ind) + _arr[ofs - ind] + carry);
            carry = new_digit / 10;
            new_digit %= 10;

            _arr[ofs - ind] = new_digit;
        }
    }

    void big_int::_sub(big_int &b_num) {
        // TODO: implement
    }
}
