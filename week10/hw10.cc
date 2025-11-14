#include "vector.h"
#include "list.h"
#include "stack.h"
#include "queue.h"

void print_vector(Vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << "\n";
    }
    std::cout << "size : " << v.size() << "\n";
}

int main() {
    Vector<int> v1 = Vector<int>(3);
    v1.PushBack(1);
    v1.PushBack(3);
    v1.PushBack(2);
    v1.PushBack(4);

    Vector<int> v2 = v1;

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

    List<char> l1 = List<char>();
    l1.PushFront('a');
    l1.PushFront('b');
    l1.PushFront('c');

    std::cout << l1.At(0) << "\n";
    std::cout << l1.At(1) << "\n";
    std::cout << l1.At(2) << "\n";
    l1.PopFront();
    l1.PopFront();
    l1.PopFront();
    std::cout << l1.size() << std::endl;    
}
