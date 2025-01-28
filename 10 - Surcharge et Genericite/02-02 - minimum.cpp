#include <iostream>

using namespace std;
template <typename T>
T& min(T& a, T& b, T& c) {
    return a < b ? a < c ? a : c : b < c ? b : c;
}

int main(){
    int    a = 5;
    int    b = 2;
    int    c = 9;

    double d = 5.0;
    double e = 2.0;
    double f = 9.0;

    cout << min(a, b, c) << endl;
    min(a, b, c) = 1;
    int& min_abc = min(a, b, c);

    cout << min(d, e, f) << endl;
    min(d, e, f) = 1;
    double& min_def = min(d, e, f);
}
