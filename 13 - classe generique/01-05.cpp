//
// Created by mauro on 06/01/25.
//

#include <iostream>
#include <vector>
#include <algorithm>

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

enum class Quadrant {I = 1,II,III,IV};

struct DansQuadrant {
    Quadrant quadrant;
    template<typename T>
    bool operator()(Point<T> p) {
        switch (quadrant) {
            case Quadrant::I: return (p.getCoord().getX() > T() && p.getCoord().getY() > T());
            case Quadrant::II: return (p.getCoord().getX() < T() && p.getCoord().getY() > T());
            case Quadrant::III: return (p.getCoord().getX() < T() && p.getCoord().getY() < T());
            case Quadrant::IV: return (p.getCoord().getX() > T() && p.getCoord().getY() < T());
            default: return false;
        }
    }
};
template <typename T>
void ListerPoints(vector<Point<T>> points){
    for_each(points.begin(), points.end(), [](Point<T> p){
        p.afficher();
        cout << endl;
    });
}

int main() {
    vector<Point<int>> dessin {{"p1",  1,  2},
                           {"p2",  4,  2},
                           {"p3",  9,  8},
                           {"p4", -1,  5},
                           {"p5",  3, -1},
                           {"p6",  7,  0}};
    ListerPoints(dessin);
    int x = 1,y = -1;
    for_each(dessin.begin(), dessin.end(), [&x,&y](Point<int>& p){ p.deplacer(x,y); });
    cout << endl;
    ListerPoints(dessin);
    return EXIT_SUCCESS;
}
