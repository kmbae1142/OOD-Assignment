#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>
#include <stdexcept>
#include <string>
#include "empty_container_exception.h"

template <typename T>
class Vector {
    public:
        explicit Vector(std::size_t capacity) : elements_(new T[capacity]), capacity_(capacity), size_(0) {};

        Vector(const Vector& vector) : elements_(nullptr), capacity_(vector.capacity_), size_(vector.size_) {
            *this = vector;
        }

        virtual ~Vector() {
            delete[] this->elements_; 
        }

        void operator=(const Vector& vector) {
            if (this == &vector) { return; }
            delete[] this->elements_;
            this->elements_ = new T[vector.capacity_];
            this->size_ = vector.size_;
            this->capacity_ = vector.capacity_;
            for (int i = 0; i < this->size_; i++) {
                this->elements_[i] = vector.elements_[i];
            }
        }

        T& operator[](const int index) {
            if (index < 0 || index >= size_) {
                throw std::out_of_range("The index is " + 
                        std::to_string(index) + 
                        ", but the size is " + 
                        std::to_string(this->size_));
            }
            return this->elements_[index];   
        }

        std::size_t size() const {
            return this->size_;
        }

        std::size_t capacity() const {
            return this->capacity_;
        }

        void PushBack(T elem) {
            if (this->size_ + 1 > this->capacity_) {
                T* new_elem = new T[this->capacity_ + 4];
                for (int i = 0; i < this->size_; i++) {
                    new_elem[i] = this->elements_[i];
                }

                delete[] this->elements_;
                this->elements_ = new_elem;
                this->capacity_ += 4;
            }
            this->elements_[this->size_++] = elem;
        }

        void PopBack() {
            if (this->IsEmpty()) {
                throw EmptyContainerException("This vector is empty");            
            }
            this->size_--;
        }

        bool IsEmpty() const {
            return this->size_ == 0;
        }

    private:
        T* elements_;
        std::size_t capacity_;
        std::size_t size_;
};

#endif // _VECTOR_H_
