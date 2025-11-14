#include "list.h"

List::List() : head(nullptr), size_(0) {}

List::List(const List& list) : head(nullptr), size_(0) {
    *this = list;
}

List::~List() {
    Elem* cur_node = this->head;

    while (cur_node != nullptr) {
        Elem* next = cur_node->next;
        delete cur_node;
        cur_node = next;
    }
}

void List::operator=(const List& list) {
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

std::size_t List::size() const {
    return this->size_;
}

int& List::At(int index) {
    assert((index >= 0 && index < this->size_) && "Out of Bound");

    Elem* cur_node = this->head;
    for (int i = 0; i < index; i++) {
        cur_node = cur_node->next;
    }

    return cur_node->value;
}

bool List::IsEmpty() const {
    return this->size_ == 0;
}

void List::PushBack(int elem) {
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

void List::PushFront(int elem) {
    Elem* new_elem = new Elem;
    new_elem->value = elem;
    new_elem->next = nullptr;
    
    if (this->head != nullptr) {
        new_elem->next = this->head;
    }

    this->head = new_elem;
    this->size_++;
}

void List::PopBack() {
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

void List::PopFront() {
    assert(!IsEmpty() && "Out of Bound");
    
    Elem* new_head = this->head->next;
    delete head;
    
    this->head = new_head;
    this->size_--;
}



