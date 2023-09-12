#pragma once
#include <iostream>

// meant to be an assertion.
#define THROW_IF(cond, code, msg) { if (cond) { std::cout << msg; exit(code); }}