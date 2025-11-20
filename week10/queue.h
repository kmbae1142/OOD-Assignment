#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "list.h"
#include <system_error>

template <typename T>
class Queue : private List<T> {
    public:
        Queue() {}
        Queue(const Queue& queue) : List<T>(queue) {}

        void operator=(const Queue& queue) {
            List<T>::operator=(queue);
        }

        std::size_t size() const {
            return List<T>::size();
        }

        void Add(T elem) {
            List<T>::PushBack(elem);
        }

        T Poll() {
            T pop_num = List<T>::At(0);
            List<T>::PopFront();
            return pop_num;
        }

        bool IsEmpty() const {
            return List<T>::IsEmpty();
        }
};

#endif // _QUEUE_H_
