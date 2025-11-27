#include <bits/stdc++.h>
#include "sort.h"

using namespace std;

class IntIncreasingOrder {
    public:
        int operator()(const int& x, const int& y) {
            if (x > y) {
                return 1;
            }
            else {
                return 0;
            }
        }
};

class IntDecreasingOrder {
    public:
        int operator()(const int& x, const int& y) {
            if (x < y) {
                return 1;
            }
            else {
                return 0;
            }
        }
};

template <typename T, typename N>
void SortAndPrint(T* container) {
    for (int n : *container) {
        cout << n << ' ';
    }
    cout << "-> ";

    Sort<T, N>(container->begin(), container->end());

    for (int n : *container) {
        cout << n << ' ';
    }
    cout << endl;
}

int main() {
    vector<int> vec = {1, 3, 5, 2, 6, 8, 4, 0};
    list<int> lst = {1, 3, 5, 2, 6, 8, 4, 0};
    
    SortAndPrint<vector<int>, IntDecreasingOrder>(&vec);
    SortAndPrint<vector<int>, IntIncreasingOrder>(&vec);
    SortAndPrint<list<int>, IntIncreasingOrder>(&lst);
}
