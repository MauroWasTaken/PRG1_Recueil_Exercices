#include <iostream>
#include <array>

using namespace std;
struct Stack{
    int size = 0;
    array <int,10> data {};
};

void display(const Stack& stack) {
    cout << "size   : " << stack.size << endl
         << "data   : [";
    for (int i = 0; i < stack.size; i++) {
        cout << stack.data[i];
        if (i != stack.size -1) cout << ", ";
    }
    cout << "]" << endl;
}

bool full(const Stack& s) {
    return s.size == 10;
}

bool empty(const Stack& s) {
    return s.size == 0;
}

void push(Stack &s, int val) {
    s.data[s.size] = val;
    s.size++;
}

void pop(Stack &s) {
    --s.size;
}
int top(const Stack& s ) {
    return s.data[s.size-1];
}
size_t size(const Stack& s) {
    return s.size;
}

int main() {

    Stack s;
    int i = 1;

    display(s);
    cout << endl;

    while (not full(s)) {
        push(s, i*=2);
    }

    cout << "top  : " << top(s)  << endl;
    cout << "size : " << size(s) << endl;
    cout << endl;

    display(s);
    cout << endl;

    while (not empty(s)) {
        pop(s);
    }

    display(s);
    cout << endl;
}