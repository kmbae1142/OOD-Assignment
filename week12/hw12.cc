#include "vector.h"
#include "list.h"
#include "safe_int.h"
#include "divide_by_zero_exception.h"
#include <stdexcept>

int main() {
    Vector<std::string> vector(3);
    vector.PushBack("a");
    vector.PushBack("b");
    vector.PushBack("c");
    try {
        std::cout<< vector[5] <<std::endl;
    }
    catch (std::out_of_range& e) {
        std::cout << e.what() << "\n";
    }

    SafeInt n1(3);
    SafeInt n2(0);
    try {
        n1 / n2;
    } catch (DivideByZeroException& e) {
        std::cout << e.what() << "\n";
    }
    SafeInt re = n1 + n2;
    std::cout << re.value() << "\n";
}
