//
// Created by mauro on 20/01/25.
//

#include <iostream>

using namespace std;

class C {
    int i;
public:
    C() : i(0) { cout << "CD " << flush; }
    C(int i) : i(i) { cout << "C" << i << " " << flush; }
    ~C() { cout << "D" << i << " " << flush; }
};
C* f(){
    C* c = new C();
    return c;
}
C* f(int i){
    C* c = new C(i);
    return c;
}
void g(C* p){
    delete p;
}
int main() {
    auto p1 = f();
    auto p2 = f(2);
    g(p2);
    p2 = f(3);
    g(p1);
    g(p2);
}