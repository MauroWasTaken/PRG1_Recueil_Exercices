//
// Created by mauro on 16/12/24.
//
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <span>
#include <algorithm>

using namespace std;
template <typename T>
ostream& operator<<(ostream &os, const span<T>& s) {
    cout << "[";
    auto first = s.begin();
    auto begin = s.begin();
    auto end = s.end();
    for (; begin != end; ++begin) {
        if(first != begin) cout << ", ";
        cout << *begin;
    }
    cout << "]";
    return os;
}
template <typename T>
struct entre {
    const T& min;
    const T& max;
    bool operator()(const T& x) {
        return x >= min && x <= max;
    }
};

int main() {
    vector v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << span(v) << endl;

    cout << count_if(v.begin(), v.end(), entre<int>{3, 6}) << endl;
    int min=3, max=6;
    cout << count_if(v.begin(), v.end(), [&min, &max](const int& x) {return x >= min && x <= max;});
    return 0;
}