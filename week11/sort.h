#ifndef _SORT_H_
#define _SORT_H_

#include <iterator>

template <typename T>
void Swap(T& elt1, T& elt2) {
    T temp = elt1;
    elt1 = elt2;
    elt2 = temp;
}

template <typename T, typename N>
void Sort(typename T::iterator begin, typename T::iterator end) {
    N comp = N();

    for (auto i = std::prev(end, 1); i != begin; --i) {
        for (auto j = begin; j != i; ++j) {
            if (comp(*j, *std::next(j))) {
                Swap(*j, *std::next(j));
            }
        }
    }
}

#endif // _SORT_H_
