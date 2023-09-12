#include "error.h"
#include "common.h"

namespace putil {
    void report(std::string msg, int error_code) {
        std::cerr << "ERROR | " << msg;
        exit(error_code);
    }

    void report(std::string location, std::string msg, int error_code) {
        std::cerr << "ERROR | " << location << " | " << msg;
    }

    void warn(std::string msg) {
        std::cerr << "WARNING | " << msg;
    }

    void warn(std::string location, std::string msg) {
        std::cerr << "WARNING | " << location << " | " << msg;
    }
}