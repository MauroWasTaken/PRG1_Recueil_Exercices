
#include <iostream>
#include <cstdlib>
#include <utility>

using namespace std;

class Point{
  public:
    void afficher()const {cout << "(" << x << ", " << y << ")" << endl; }
    void deplacer(double dx,double dy) {x += dx, y += dy;}
    void setX(double x){this->x = x;}
    void setY(double y){this->y = y;}
    double getX()const{return x;}
    double getY()const{return y;}
  private:
    double x,y;
};


using namespace std;

int main() {
    Point centre;
    centre.setX(0);
    centre.setY(0);
    centre.afficher();

    Point p;
    p.setX(1.2);
    p.setY(2.4);
    p.afficher();

    p.deplacer(0.8, 0.6);
    p.afficher();

    p.setX(5.5);
    p.setY(10.3);
    cout << p.getX() << " -- " << p.getY() << endl;
}
