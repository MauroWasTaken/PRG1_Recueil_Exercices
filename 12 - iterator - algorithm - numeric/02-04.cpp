//
// Created by mauro on 16/12/24.
//
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <span>

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
    cout << "]" << endl;
    return os;
}
template <typename T, typename It1, typename It2>
vector<T> concat_tab(It1 begin1, It1 end1, It2 begin2, It2 end2) {
    for(;begin1 != end1; ++begin1, ++begin2) {
        vector<T> v (distance(begin1, end1) + distance(begin2, end2));

        typename vector<T>::iterator it = v.begin();

        while(begin1 != end1)
            *it++ = *begin1++;

        while(begin2 != end2)
            *it++ = *begin2++;

        return v;
    }
}

int main() {
    vector v {11, 12, 13};
    array  a {21, 22, 23, 24, 25};

    cout << "vector   : " << span<int>(v) << endl;
    cout << "array    : " << span<int>(a) << endl;

    vector r = concat_tab<int>(v.begin(), v.end(),
                              a.begin(), a.end());

    cout << "resultat : " << span<int>(r) << endl;
}