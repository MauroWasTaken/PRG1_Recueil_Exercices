//
// Created by mauro on 12/12/24.
//

#ifndef POINT_H
#define POINT_H
#include <iostream>
class Point{
public:
    Point();
    Point(double x, double y);
    void afficher()const;
    void deplacer(double dx,double dy);
    void setX(double x);
    void setY(double y);
    double getX()const;
    double getY()const;
    friend std::ostream& operator << (std::ostream & os, const Point & p);
    Point operator + (const Point& p2) const;
    Point operator + (double d) const;
    Point operator* (double d)const;
    friend Point operator * (double d, const Point& p1);
    friend Point operator + (double d, const Point& p1);
    friend bool operator ==(const Point& p1, const Point& p2);
private:
    double x,y;
};

#endif //POINT_H
