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

template <typename T>
class Point {
public:
    Point():nom(string()),coord(Coord(0,0)) {}
    Point(string s):nom(s),coord(Coord(0,0)) {}
    Point(string s, Coord<T> c):nom(s),coord(c) {}
    Point(string s, T x, T y):nom(s),coord(Coord(x,y)) { }
    void afficher()const {
        cout << nom;
        this->coord.afficher();
    }
    void deplacer(T x, T y){ this->coord.deplacer(x,y); }
    [[nodiscard]] string getNom()const{ return nom;}
    void setNom(string s){ this->nom = s;}
    void setCoord(T x, T y){ this->coord = Coord<T>(x,y);}
    void setCoord(const Coord<T>& c){ this->coord = c;}
    [[nodiscard]]Coord<T> getCoord()const{ return this->coord;}
private:
    string nom;
    Coord<T> coord;
};

int main(){
    const Point<int> origin;

    cout << "p1       : ";
    Point<int> p1("p1"s);
    p1.afficher();
    cout << endl;

    cout << "p2       : ";
    Point<double> p2("p2"s, Coord(1.2, 3.4));
    p2.afficher();
    cout << endl;

    cout << "p3       : ";
    Point<double> p3("p3"s, 1.2, 3.4);
    p3.afficher();
    cout << endl;

    cout << "p3.1     : ";
    p3.setNom("p3.1"s);
    p3.afficher();
    cout << endl;

    cout << "p1(-1, 1): ";
    p1.setCoord(Coord(-1, 1));
    p1.afficher();
    cout << endl;

    cout << "p1->     : ";
    p1.deplacer(-1, 1);
    p1.afficher();
    cout << endl;

    cout << "p1(x)    : ";
    cout << p1.getNom() << " " << p1.getCoord().getX();
}