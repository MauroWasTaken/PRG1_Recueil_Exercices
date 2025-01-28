#include <iostream>
#include <array>
#include "Stack.h"

using namespace std;

int main() {

    Stack<int, 10> s;
    int i = 1;

    s.display();
    cout << endl;

    while (not s.full()) {
        s.push(i*=2);
    }

    cout << "top  : " << s.top() << endl;
    cout << "size : " << s.size() << endl;
    cout << endl;

    s.display();
    cout << endl;

    while (not s.empty()) {
        s.pop();
    }

    s.display();
    cout << endl;
}