#include <iostream>
#include "util.h"

int main() {
    Util* calc = new Util();
    std::cout << calc->Add(2, 3);
    return 0;
}
