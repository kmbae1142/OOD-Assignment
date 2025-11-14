#include "vector.h"
#include "list.h"
#include "stack.h"
#include "queue.h"

void print_vector(Vector& v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << "\n";
    }
    std::cout << "size : " << v.size() << "\n";
}

int main() {
    Vector v1 = Vector(3);
    v1.PushBack(1);
    v1.PushBack(3);
    v1.PushBack(2);
    v1.PushBack(4);

    Vector v2 = v1;

    print_vector(v2);

    print_vector(v1);
    v1.PopBack();
    print_vector(v1);
    v1.PopBack();
    print_vector(v1);
    v1.PopBack();
    print_vector(v1);
    v1.PopBack();
    std::cout << v1.IsEmpty() << "\n";
    std::cout << v1.capacity() << "\n";

    List l1 = List();
    l1.PushFront(5);
    l1.PushFront(3);
    l1.PushFront(2);

    std::cout << l1.At(0) << "\n";
    std::cout << l1.At(1) << "\n";
    std::cout << l1.At(2) << "\n";
    l1.PopFront();
    l1.PopFront();
    l1.PopFront();
    std::cout << l1.size() << std::endl;    
}
