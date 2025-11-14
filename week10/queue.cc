#include "queue.h"

Queue::Queue() {}

Queue::Queue(const Queue& queue) : List(queue) {}

void Queue::operator=(const Queue& queue) {
    List::operator=(queue);
}

std::size_t Queue::size() const {
    return List::size();
}

void Queue::Add(int elem) {
    List::PushBack(elem);
}

int Queue::Poll() {
    int pop_num = List::At(0);
    List::PopFront();
    return pop_num;
}

bool Queue::IsEmpty() const {
    return List::IsEmpty();
}
