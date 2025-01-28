//
// Created by mauro on 06/01/25.
//

#include <iostream>

using namespace std;
template <typename T>
class Coord{
    public:
    Coord(): x(T()), y(T()) {}
    Coord(T x, T y):x(x), y(y) {}
    void afficher() const {
        cout << "(" << x << ", " << y <<")";
    }
    void setCoord(T x, T y) {
        this->x = x;
        this->y = y;
    }
    void deplacer(T x, T y) {
        this->x += x;
        this->y += y;
    }
    T getX() const {
        return this->x;
    }
    T getY() const {
        return this->y;
    }
    private:
    T x, y;
};

int main(){
    cout << "origine  : ";
    const Coord<int> origin;
    origin.afficher();
    cout << endl;

    cout << "p1       : ";
    Coord<int> p1;
    p1.setCoord(1, 2);
    p1.afficher();
    cout << endl;

    cout << "p2       : ";
    Coord<double> p2(3, 4);
    p2.afficher();
    cout << endl;

    cout << "p2->     : ";
    p2.deplacer(1, 1);   // conversion int => double
    cout << "(" << p2.getX() << ", " << p2.getY() << ")";
    cout << endl;
}