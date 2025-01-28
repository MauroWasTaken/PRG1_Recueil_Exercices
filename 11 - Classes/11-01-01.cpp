
#include <iostream>

using namespace std;

struct Point{
    double x,y;
    void afficher()const {cout << "(" << x << ", " << y << ")" << endl; }
    void deplacer(double dx,double dy) {x += dx, y += dy;}
};

int main() {
    Point centre{};
    centre.afficher();

    Point p{1.2, 2.4};
    p.afficher();
    p.deplacer(0.8, 0.6);
    p.afficher();

    p.x = 5.5;
    p.y = 10.3;
    cout << p.x << " -- " << p.y << endl;
}
