
#include <iostream>
#include <cstdlib>
#include <utility>

using namespace std;

class Point{
private:
    double x,y, xMax = 100, yMax = 100;
    static size_t nb_points;
public:
    Point() {x = 0; y = 0; ++nb_points;};
    Point(double x, double y) {
        this->x = x;
        this->y = y;
        ++nb_points;
    };
    Point(double x, double y, double xMax, double yMax) {
        this->xMax = xMax;
        this->yMax = yMax;
        this->x = x;
        this->y = y;
        ++nb_points;
    };
    Point(const Point &other) {
        this->x = other.x;
        this->y = other.y;
        this->xMax = other.xMax;
        this->yMax = other.yMax;
        ++nb_points;
    }
    ~Point() {--nb_points;};
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
    static size_t getNbPoints(){
        return nb_points;
    }

};
size_t Point::nb_points = 0;

int main() {

  Point p1(1.2, 2.4);
  p1.afficher();

  cout << "Nombre de points : " << Point::getNbPoints() << endl;
  cout << "-------------------------------------------" << endl;

  {
    Point p2(3., 4.2, 10., 10.);
    p2.afficher();

    cout << "Nombre de points : " << Point::getNbPoints() << endl;
    cout << "-------------------------------------------" << endl;

    p2 = p1;
    p2.afficher();

    cout << "Nombre de points : " << Point::getNbPoints() << endl;
    cout << "-------------------------------------------" << endl;

    Point p3 = p2;
    p3.afficher();

    cout << "Nombre de points : " << Point::getNbPoints() << endl;
    cout << "-------------------------------------------" << endl;
  }

  Point p4(5, 10);
  p4.afficher();

  cout << "Nombre de points : " << Point::getNbPoints() << endl;
  cout << "-------------------------------------------" << endl;
}
