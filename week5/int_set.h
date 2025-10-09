#ifndef _INT_SET_H_
#define _INT_SET_H_

#include <assert.h>
#include <iostream>
#include <functional>

class IntSet {
    public:
        explicit IntSet(int capacity);
        IntSet(const IntSet& int_set);
        ~IntSet();
        int capacity() const;
        int size() const;
        int* elements() const;
        int operator[] (int index) const;
        void Add(int value);
        void Add(const IntSet& int_set);
        void Map(std::function<int(int)> func);
        bool ForAll(std::function<bool(int)> func);
    private:
        int capacity_;
        int size_;
        int* elements_;
};

#endif // _INT_SET_H_
