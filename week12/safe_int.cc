#include "safe_int.h" 
#include "divide_by_zero_exception.h"
#include <limits>
#include <string>

const int kMax = std::numeric_limits<int>::max();
const int kMin = std::numeric_limits<int>::min();

SafeInt::SafeInt(int val) : value_(val) {}

SafeInt SafeInt::operator+(const SafeInt& operand) const {
    SafeInt result = SafeInt(this->value_);
    int x_opd = result.value_;
    int y_opd = operand.value_;

    if (x_opd > 0 && y_opd > 0) {
        if (x_opd > kMax - y_opd) {
            throw std::overflow_error("Integer overflow occurs in " + std::to_string(x_opd) + " + " + std::to_string(y_opd));
        }
    }
    else if (x_opd < 0 && y_opd < 0) {
        if (x_opd < kMin - y_opd) {
            throw std::overflow_error("Integer overflow occurs in " + std::to_string(x_opd) + " + " + std::to_string(y_opd));
        }
    }

    result.value_ = x_opd + y_opd;
    return result;
}

SafeInt SafeInt::operator-(const SafeInt& operand) const {
    SafeInt result = SafeInt(this->value_);
    int x_opd = result.value_;
    int y_opd = operand.value_;
    
    if (x_opd < 0 && y_opd > 0) {
        if (x_opd < kMin + y_opd) {
            throw std::overflow_error("Integer overflow occurs in " + std::to_string(x_opd) + " - " + std::to_string(y_opd));
        } 
    }
    else if (x_opd > 0 && y_opd < 0) {
        if (x_opd > kMax + y_opd) {
            throw std::overflow_error("Integer overflow occurs in " + std::to_string(x_opd) + " - " + std::to_string(y_opd));
        }
    }

    result.value_ = x_opd - y_opd;
    return result;
}

SafeInt SafeInt::operator*(const SafeInt& operand) const {
    SafeInt result = SafeInt(this->value_);
    int x_opd = result.value_;
    int y_opd = operand.value_;

    if ((x_opd > 0 && y_opd > 0) || (x_opd < 0 && y_opd < 0)) {
        if (x_opd > kMax / y_opd) {
            throw std::overflow_error("Integer overflow occurs in " + std::to_string(x_opd) + " * " + std::to_string(y_opd)); 
        }
    }
    else if ((x_opd < 0 && y_opd > 0) || (x_opd > 0 && y_opd < 0)) {
        if (x_opd < 0) {
            if (x_opd < kMin / y_opd) {
                throw std::overflow_error("Integer overflow occurs in " + std::to_string(x_opd) + " * " + std::to_string(y_opd)); 
            }
        }
        else {
            if (x_opd > kMin / y_opd) {
                throw std::overflow_error("Integer overflow occurs in " + std::to_string(x_opd) + " * " + std::to_string(y_opd)); 
            }   
        }
    }

    result.value_ = x_opd * y_opd;
    return result;
}

SafeInt SafeInt::operator/(const SafeInt& operand) const {
    SafeInt result = SafeInt(this->value_);
    int x_opd = result.value_;
    int y_opd = operand.value_;
    
    if (y_opd == 0) {
        throw DivideByZeroException(("Divide-by-zero exception occurs in " + std::to_string(x_opd) + " / " + std::to_string(y_opd)).c_str());
    }

    result.value_ = x_opd / y_opd;
    return result;
}

SafeInt SafeInt::operator%(const SafeInt& operand) const {
    SafeInt result = SafeInt(this->value_);
    int x_opd = result.value_;
    int y_opd = operand.value_;

    if (y_opd == 0) {
        throw DivideByZeroException(("Divide-by-zero exception occurs in " + std::to_string(x_opd) + " % " + std::to_string(y_opd)).c_str());
    }

    result.value_ = x_opd % y_opd;
    return result;
}

int SafeInt::value() const {
    return this->value_;
}
