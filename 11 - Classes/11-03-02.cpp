
#include <iostream>
#include <cstdlib>
#include <utility>

using namespace std;

class Point{
  public:
    Point() {x = 0; y = 0;};
    Point(double x, double y) {this->x = x; this->y = y;};
    void afficher()const {cout << "(" << x << ", " << y << ")" << endl; }
    void deplacer(double dx,double dy) {x += dx, y += dy;}
    void setX(double x){this->x = x;}
    void setY(double y){this->y = y;}
    double getX()const{return x;}
    double getY()const{return y;}
  private:
    double x,y;
};

int main() {
    Point centre;
    centre.afficher();

    Point p(1.2,2.4);
    p.afficher();

    p.deplacer(0.8, 0.6);
    p.afficher();

    p.setX(5.5);
    p.setY(10.3);
    cout << p.getX() << " -- " << p.getY() << endl;
}
