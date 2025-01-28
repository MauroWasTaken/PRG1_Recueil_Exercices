#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

const char* BOOL_EN_FRANCAIS [] = { "faux", "vrai" };

// A COMPLETER ICI



int main() {

    cout << opposer(42) << " "
         << opposer(42u) << " "
         << boolalpha << opposer(true) << " "
         << opposer(false) << " "
         << opposer(-3.14) << endl;

    array<int,0> a0;                                      cout << a0 << endl;

    array<int, 4> a4 { 1, 2, 3,  4 };                     cout << a4 << endl;
    transformer(a4, opposer<int>);                        cout << a4 << endl;

    array<bool,0> b0;                                     cout << b0 << endl;

    array<bool, 5> b5 { true, false, false, true, true }; cout << b5 << endl;
    transformer(b5, opposer<bool>);                       cout << b5 << endl;

    array<double,0> c0;                                   cout << c0 << endl;

    array<double, 3> c3 { 1.61, 2.72, 3.14 };             cout << c3 << endl;
    transformer(c3, opposer<double>);                     cout << c3 << endl;
}