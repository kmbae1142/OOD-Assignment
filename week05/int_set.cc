#include "int_set.h"


IntSet::IntSet(int capacity) : capacity_(capacity), size_(0), elements_(new int[capacity_]) {
    
}

IntSet::IntSet(const IntSet& int_set) : capacity_(int_set.capacity_), size_(int_set.size_), elements_(new int[capacity_]) {
    
    for (int i = 0; i < size_; i++) {
       this->elements_[i] = int_set.elements_[i];
    }
}

IntSet::~IntSet() {
    delete[] elements_;
}

int IntSet::capacity() const {
    return this->capacity_;
}

int IntSet::size() const {
    return this->size_;
}

int* IntSet::elements() const {
    return this->elements_;
}

int IntSet::operator[](int index) const {
    assert((index >= 0 && index < this->size_) && "Out of bound");
    return this->elements_[index];
}

void IntSet::Add(int value) {
    int size = this->size_;

    for (int i = 0; i < size; i++) {
        if (this->elements_[i] == value) {
            return;
        }
    }
    
    if (size + 1 > this->capacity_) {
        this->capacity_ += 4;
        int* new_elem = new int[this->capacity_];
        for (int i = 0; i < size; i++) { new_elem[i] = this->elements_[i]; }

        delete[] this->elements_;
        this->elements_ = new_elem;
    }

    this->elements_[size] = value;
    this->size_++;
}

void IntSet::Add(const IntSet& int_set) {
    for (int i = 0; i < int_set.size(); i++) {
        this->Add(int_set.elements()[i]);
    }
}

void IntSet::Map(std::function<int(int)> func) {
    int old_size = this->size_;
    int* copy_elem = new int[this->size_];
    for (int i = 0; i < old_size; i++) {
        copy_elem[i] = this->elements_[i];
    }

    delete[] this->elements_;
    this->elements_ = new int[this->capacity_];
    this->size_ = 0;

    for (int i = 0; i < old_size; i++) {
        this->Add(func(copy_elem[i]));
    }
    delete[] copy_elem;
}

bool IntSet::ForAll(std::function<bool(int)> func) {
    for (int i = 0; i < size_; i++) {
        if (!func(elements_[i])) { 
            return false;
        }
    }
    return true;
}

