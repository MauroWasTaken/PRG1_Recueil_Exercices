#include <vector>
#include <array>
#include <iostream>
#include <string>
#include "Tri.h"

using namespace std;

template <typename T>
void exchange(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void show(const span <T> s) {
    for (const T& t : s) {
        cout << t << " ";
    }
    cout << endl;
}

int main(){
    vector v      {6, 2, 8, 7, 1, 3};
    array  a      {"chien"s, "chat"s, "souris"s, "poisson"s};
    double t[ ] = {6.1, 2.2, 8.3, 7.4, 1.5, 3.6};

    show<int>(v);
    show<string>(a);
    show<double>(t);

    sort<int>(v);
    sort<string>(a);
    sort<double>(t);

    show<int>(v);
    show<string>(a);
    show<double>(t);
}
