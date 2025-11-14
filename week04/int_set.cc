#include "int_set.h"


IntSet::IntSet(int capacity) : capacity_(capacity), size_(0), elements_(new int[capacity_]()) {
    
}

IntSet::IntSet(const IntSet& int_set) : capacity_(int_set.capacity_), size_(int_set.size_), elements_(new int[capacity_]()) {
    
    for (int i = 0; i < size_; i++) {
       this->elements_[i] = int_set.elements_[i];
    }
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

void IntSet::Add(int value) {
    int size = this->size_;

    for (int i = 0; i < size; i++) {
        if (this->elements_[i] == value) {
            return;
        }
    }

    assert((size + 1) <= this->capacity_ && "Exceeded capacity");
    this->elements_[size] = value;
    this->size_++;
}

void IntSet::Add(const IntSet& int_set) {
    int curSize = this->size_;
    int* temp = new int[this->capacity_];
    bool flag = false;
    bool isFreed = false;
    
    for (int i = 0; i < this->capacity_; i++) { temp[i] = this->elements_[i]; }

    for (int curIndex = 0; curIndex < int_set.size_; curIndex++) {
        flag = false;
        for (int i = 0; i < curSize; i++) {
            if (this->elements_[i] == int_set.elements_[curIndex]) {
                flag = true;
                break;
            }
        }

        if (flag) { continue; }

        if (curSize + 1 > this->capacity_) {
            for (int i = 0; i < this->capacity_; i++) { this->elements_[i] = temp[i]; }
            delete[] temp;
            isFreed = true;
            assert(curSize + 1 <= this->capacity_ && "Exceeded capacity");
        }
        this->elements_[curSize++] = int_set.elements_[curIndex];
    }

    this->size_ = curSize;
    if (!isFreed) { delete[] temp; }
}

void IntSet::Map(std::function<int(int)> func) {
    for (int i = 0; i < size_; i++) {
        elements_[i] = func(elements_[i]);
    }
}

bool IntSet::ForAll(std::function<bool(int)> func) {
    for (int i = 0; i < size_; i++) {
        if (!func(elements_[i])) { 
            return false;
        }
    }
    return true;
}

