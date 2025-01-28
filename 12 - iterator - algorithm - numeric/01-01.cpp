//
// Created by mauro on 16/12/24.
//
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <list>

using namespace std;
template <typename Iterator>
void display(Iterator begin, Iterator end) {
  for (Iterator it = begin; it != end; ++it) {
      cout << *it    << "\t";
      cout << (const void*)&(*it) << endl;
  }
}

int main() {
    array  a  {1, 2, 3};
    vector v  {1.1, 2.2, 3.3};
    string s  ("HEIG-VD"s);
    list   l  {"chien"s, "chat"s, "souris"s};

    cout << "array"   << endl;    display(a.cbegin(), a.cend());
    cout << "vector"  << endl;    display(v.cbegin(), v.cend());
    cout << "string"  << endl;    display(s.cbegin(), s.cend());
    cout << "list"    << endl;    display(l.cbegin(), l.cend());
}