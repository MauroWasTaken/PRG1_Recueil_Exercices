
#include <iostream>
#include <cstdlib>
#include <utility>

using namespace std;

class Point{
  public:
    Point() {x = 0; y = 0;};
    Point(double x, double y) {
      this->x = x;
      this->y = y;
    };
  Point(double x, double y, double xMax, double yMax) {
      this->xMax = xMax;
      this->yMax = yMax;
      this->x = x;
      this->y = y;
    };
    void setX(double x){
      if(x < xMax && x > 0 ) this->x = x;
    }
    void setY(double y){
      if(y < yMax && y > 0 ) this->y = y;
    }
    double getX()const{return x;}
    double getY()const{return y;}
    void afficher()const {
        cout << "(" << x << ", " << y << "), contraintes: [0,"<< xMax << "]x[0," << yMax << "]" << endl;
    }

    void deplacer(double dx,double dy) {
      setX(x + dx);
      setY(y + dy);
    }
  private:
    double x,y, xMax = 100, yMax = 100;
};

int main() {
    Point p1(1.2, 2.4);
    cout << "p1"; p1.afficher();
    p1.deplacer(1., 3.);
    cout << "p1"; p1.afficher();
    p1.setX(4.);
    cout << "p1"; p1.afficher();
    p1.setY(7.);
    cout << "p1"; p1.afficher();

    Point p2(3., 4.2, 10., 10.);
    cout << "p2"; p2.afficher();
    p2.deplacer(15, 2);
    cout << "p2"; p2.afficher();
    p2.deplacer(3, 2);
    cout << "p2"; p2.afficher();
    p2.setX(-3);
    cout << "p2"; p2.afficher();
    p2.setY(12);
    cout << "p2"; p2.afficher();
}