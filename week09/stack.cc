#include "stack.h"

Stack::Stack(std::size_t capacity) : Vector(capacity) {}

Stack::Stack(const Stack& stack) : Vector(stack) {}

void Stack::operator=(const Stack& stack) {
    Vector::operator=(stack);     
}

std::size_t Stack::size() const {
    return Vector::size();
}

std::size_t Stack::capacity() const {
    return Vector::capacity();
}

void Stack::Push(int elem) {
    Vector::PushBack(elem);
}

int Stack::Pop() {
    int pop_num = Vector::operator[](static_cast<int>(Vector::size()) - 1);
    Vector::PopBack();
    return pop_num;
}

bool Stack::IsEmpty() const {
    return Vector::IsEmpty();
}
