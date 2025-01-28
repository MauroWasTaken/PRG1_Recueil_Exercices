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
template <typename Iterateur>
void afficher_vect_iter (const vector<Iterateur>& v) {
    cout << "[";
    for (size_t i=0; i<v.size(); ++i) {
        if (i) cout << ", ";
        cout << *v[i];
    }
    cout << "]";
}
template <typename T>
bool meme_elements (const span<T>& s1, const span<T>& s2) {
    typename span<T>::const_iterator it = s1.cbegin();
    for (; it != s1.cend(); ++it) {
        if(find(s2.begin(), s2.end(), *it) == s2.end()) return false;
    }
    return true;
}
int main() {

    array  a {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2};

    cout << span<int>(a) << endl;
    cout << span<int>(v) << endl;

    cout << meme_elements<int>(span<int>(a), span<int>(v));
}