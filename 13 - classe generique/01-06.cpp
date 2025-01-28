#include <iostream>
#include <array>

using namespace std;
template <typename T, size_t n>
class Stack{
    size_t _size = 0;
    array <T,n> data {};
    public:
   void display() const {
        cout << "size   : " << this->_size << endl
             << "data   : [";
        for (T i = 0; i < this->_size; i++) {
            cout << this->data[i];
            if (i != this->_size -1) cout << ", ";
        }
        cout << "]" << endl;
    }

    [[nodiscard]] bool full() const {
        return this->_size == 10;
    }

    [[nodiscard]] bool empty() const {
        return this->_size == 0;
    }

    void push(T val) {
        this->data[this->_size] = val;
        ++this->_size;
    }

    void pop() {
        --this->_size;
    }

    [[nodiscard]] T top() const {
        return this->data[this->_size-1];
    }

    [[nodiscard]] size_t size() const {
        return this->_size;
    }
};



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