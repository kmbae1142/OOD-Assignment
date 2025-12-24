#include "divide_by_zero_exception.h"
#include <stdexcept>

DivideByZeroException::DivideByZeroException(const char* what) : std::runtime_error(what) {}
