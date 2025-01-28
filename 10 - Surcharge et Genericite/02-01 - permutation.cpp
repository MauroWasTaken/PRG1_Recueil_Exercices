#include <iostream>

using namespace std;

template <typename T1, typename T2, typename T3>
void permutation(T1& a, T2& b, T3& c){
    auto t = a;
    a = b;
    b = c;
    c = t;
}

int main(){
    int a = 10;
    double b = 2.7;
    float c = 3.2;
    cout << "a = " << a << " b = " << b << " c = " << c << endl;
    permutation(a,b,c);
    cout << "a = " << a << " b = " << b << " c = " << c << endl;
}