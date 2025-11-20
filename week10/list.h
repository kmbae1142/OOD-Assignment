#ifndef _LIST_H_
#define _LIST_H_

#include <assert.h>
#include <iostream>

template <typename T>
class List {
    public:
        List() : head(nullptr), size_(0) {}

        List(const List& list) : head(nullptr), size_(0) {
            *this = list;
        }

        virtual ~List() {
            Elem* cur_node = this->head;

            while (cur_node != nullptr) {
                Elem* next = cur_node->next;
                delete cur_node;
                cur_node = next;
            }
        }

        void operator=(const List& list) {
            if (this == &list) { return; }

            Elem* cur_node = this->head;

            while (cur_node != nullptr) {
                Elem* next = cur_node->next;
                delete cur_node;
                cur_node = next;
            }

            if (list.head != nullptr) {
                Elem* old_node = list.head;
                Elem* new_node = new Elem;

                new_node->value = old_node->value;
                new_node->next = nullptr;
                this->head = new_node;

                old_node = old_node->next;
                while (old_node != nullptr) {
                    Elem* copy_node = new Elem;
                    copy_node->value = old_node->value;
                    copy_node->next = nullptr;

                    new_node->next = copy_node;
                    new_node = new_node->next;
                    old_node = old_node->next;
                }
            }
            else {
                this->head = nullptr;
            }

            this->size_ = list.size_;
        }

        std::size_t size() const {
            return this->size_;
        }

        void PushBack(T elem) {
            Elem* new_elem = new Elem;
            new_elem->value = elem;
            new_elem->next = nullptr;

            if (this->head != nullptr) {
                Elem* cur_node = this->head;
                while (cur_node->next != nullptr) {
                    cur_node = cur_node->next;
                }
                cur_node->next = new_elem;
            }
            else {
                this->head = new_elem;
            }

            this->size_++;
        }

        void PushFront(T elem) {
            Elem* new_elem = new Elem;
            new_elem->value = elem;
            new_elem->next = nullptr;

            if (this->head != nullptr) {
                new_elem->next = this->head;
            }

            this->head = new_elem;
            this->size_++;
        }

        void PopBack() {
            assert(!IsEmpty() && "Out of Bound");

            Elem* cur_node = head;
            Elem* prev_node = nullptr;

            while (cur_node->next != nullptr) {
                prev_node = cur_node;
                cur_node = cur_node->next;
            }

            delete cur_node;

            if (prev_node != nullptr) {
                prev_node->next = nullptr;
            }
            else {
                this->head = nullptr;
            }

            this->size_--;
        }

        void PopFront() {
            assert(!IsEmpty() && "Out of Bound");

            Elem* new_head = this->head->next;
            delete head;

            this->head = new_head;
            this->size_--;
        }

        T& At(int index) {
            assert((index >= 0 && index < this->size_) && "Out of Bound");

            Elem* cur_node = this->head;
            for (int i = 0; i < index; i++) {
                cur_node = cur_node->next;
            }

            return cur_node->value;
        }

        bool IsEmpty() const {
            return this->size_ == 0;
        }

    private:
        struct Elem {
            T value;
            Elem* next;
    };
        Elem* head;
        std::size_t size_;
};

#endif // _LIST_H_
