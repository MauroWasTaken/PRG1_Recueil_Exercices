//
// Created by mauro on 12/12/24.
//
#include <iostream>

#include "Point.h"

using namespace std;

Point::Point(){x = 0; y = 0;};
Point::Point(double x, double y) {this->x = x; this->y = y;};
void Point::afficher()const {cout << *this << endl; }
void Point::deplacer(double dx,double dy) {x += dx, y += dy;}
void Point::setX(double x){this->x = x;}
void Point::setY(double y){this->y = y;}
double Point::getX()const{return x;}
double Point::getY()const{return y;}
Point Point::operator+ (const Point& p2) const {
    return {x+p2.x,y+p2.y};
}
Point Point::operator + (double d) const {
    return {x+d,y+d};
}
Point Point::operator* (const double d)const {
    return {x*d,y*d};
}
Point operator * (const double d, const Point& p1) {
    return p1 * d;
}
Point operator + (double d, const Point& p1) {
    return p1 + d;
}
ostream& operator<< (ostream & os, const Point & p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
};
bool operator ==(const Point& p1, const Point& p2) {
    return p1.x == p2.x && p1.y == p2.y;
}