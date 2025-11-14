#include "vector.h"

Vector::Vector(std::size_t capacity) : elements_(new int[capacity]), capacity_(capacity), size_(0) {}

Vector::Vector(const Vector& vector) : capacity_(vector.capacity_), size_(vector.size_) {
    this->elements_ = new int[this->capacity_];
    for (int i = 0; i < this->size_; i++) {
        this->elements_[i] = vector.elements_[i];
    }
}

Vector::~Vector() {
    delete[] this->elements_;
}

void Vector::operator=(const Vector& vector) {
    delete[] this->elements_;
    this->elements_ = new int[vector.capacity_];
    this->size_ = vector.size_;
    for (int i = 0; i < this->size_; i++) {
        this->elements_[i] = vector.elements_[i];
    }
}

int& Vector::operator[](const int index) {
    assert((index < size_ && index >= 0) && "Out of Bound");
    return this->elements_[index];
}

std::size_t Vector::size() const {
    return this->size_;
}

std::size_t Vector::capacity() const {
    return this->capacity_;
}

void Vector::PushBack(int elem) {
    if (this->size_ + 1 > this->capacity_) {
        int* new_elem = new int[this->capacity_ + 4];
        for (int i = 0; i < this->size_; i++) {
            new_elem[i] = this->elements_[i];
        }

        delete[] this->elements_;
        this->elements_ = new_elem;
        this->capacity_ += 4;
    }
    this->elements_[this->size_++] = elem;
}

void Vector::PopBack() {
    assert(!this->IsEmpty() && "Out of Bound");
    this->size_--;
}

bool Vector::IsEmpty() const {
    return this->size_ == 0;
}

