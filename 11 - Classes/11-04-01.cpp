#include <iostream>
#include <cstdlib>
#include <utility>
#include <iomanip>

using namespace std;

class Point{
  public:
    Point() {x = 0; y = 0;};
    Point(double x, double y) {this->x = x; this->y = y;};
    void afficher()const {cout << *this << endl; }
    void deplacer(double dx,double dy) {x += dx, y += dy;}
    void setX(double x){this->x = x;}
    void setY(double y){this->y = y;}
    double getX()const{return x;}
    double getY()const{return y;}
    friend ostream& operator << (ostream & os, const Point & p) {
      os << "(" << p.x << ", " << p.y << ")";
      return os;
    };
    friend Point operator + (Point& p1, Point& p2) {
      return Point(p1.x+p2.x,p1.y+p2.y);
    }
    friend Point operator * (Point& p1, double d) {
      return Point(p1.x*d,p1.y*d);
    }
    friend Point operator * (double d, Point& p1) {
      return p1 * d;
    }
  friend bool operator ==(Point& p1, Point& p2) {
      return p1.x == p2.x && p1.y == p2.y;
    }
  private:
    double x,y;
};

int main() {

    Point p1(1.2, 2.4);
    Point p2(3., 4.2);

    cout << "p1" << p1 << ", p2" << p2 << endl;

    cout << "p1 + p2 = " << p1 + p2 << endl;
    cout << "p2 + p1 = " << p2 + p1 << endl;

    cout << "p1 * 2. = " << p1 * 2. << endl;
    cout << "3. * p1 = " << 3. * p1 << endl;

    cout << (p1 == p2 ? "p1 == p2" : "p1 != p2") << endl;
    Point p3(p1);
    cout << (p1 == p3 ? "p1 == p3" : "p1 != p3") << endl;
}