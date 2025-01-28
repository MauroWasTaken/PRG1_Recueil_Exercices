#include <iostream>

using namespace std;

class MonEntier{
public:
    MonEntier(int i = 0):i(i){};
    friend ostream& operator<<(ostream& os, const MonEntier& mon) {
        os << mon.i;
        return os;
    };
    bool operator==(const MonEntier& i2) const {
        return (*this).i== i2.i;
    };
    bool operator!=(const MonEntier& i2) const {
        return !((*this).i == i2.i);
    };
    MonEntier& operator++() {
        ++(*this).i;
        return (*this);
    };
    MonEntier operator++(int) {
        auto copy = (*this);
        ++(*this).i;
        return copy;
    };
    MonEntier operator+(const MonEntier& i2) const {
        return {(*this).i + i2.i};
    };
    MonEntier& operator+=(const MonEntier& i2) {
        return *this = *this + i2;
    }
private:
    int i;
};

int main() {
    MonEntier m0, m1(1), m2 = 5;
    const MonEntier m3{7};

    cout << m0 << endl
         << m1 << endl;
    

    cout << boolalpha;
    cout << (m0 == m1) << endl;
    cout << (m0 != m1) << endl;
    cout << noboolalpha;

    cout << m1++ << endl;
    cout << m1 << endl;
    cout << ++m1 << endl;

    cout << m1 + m2 << endl;
    m1 += m2;
    cout << m1 << endl;
    cout << m3 + m2 << endl;

    return EXIT_SUCCESS;
}