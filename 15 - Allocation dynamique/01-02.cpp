//
// Created by mauro on 20/01/25.
//

#include <iostream>

using namespace std;

class C {
    int i;
public:
    C() : i(0) { cout << "CD " << flush; }
    C(int i) : i(i) { cout << "C" << i << " " << flush; } ~C() { cout << "D" << i << " " << flush; }
};
void* f(){
    return ::operator new(sizeof(C));
}
C* f(void* ptr, const int i){
    return new(ptr) C(i);
}
C* f(void* ptr){
    return new(ptr) C();
}

void g(C* ptr){
    ptr->~C();
}
int main() {
    void *p1 = f(), *p2 = f();
    f(p1);
    f(p2,4);
    g((C*)p2);
    f(p2,1);
    g((C*)p1);
    ::operator delete(p1);
    g((C*)p2);
    ::operator delete(p2);
}