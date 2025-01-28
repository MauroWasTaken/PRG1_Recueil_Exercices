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
template <typename T, typename Iterator>
vector<Iterator> vect_iter_val (const vector<T>& v, const T& t) {
    vector<Iterator> vi;
    typename vector<T>::const_iterator it = v.cbegin();
    for (; it != v.cend(); ++it) {
        if ( *it == t )  vi.push_back(it);
    }
    return vi;
}
int main() {
    const vector v {1, 2, 3, 2, 4, 2, 2, 6, 2};
    using const_iterator = vector<int>::const_iterator;
    cout << span(v) << endl;
    afficher_vect_iter(vect_iter_val<int, const_iterator>(v, 2));
    return 0;
}