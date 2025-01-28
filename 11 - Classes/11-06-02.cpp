#include <iostream>
#include <cstdlib>

#include "Point.h"

using namespace std;

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
    }

    Point p3(5, 10);
    p3.afficher();

    cout << "Nombre de points : " << Point::getNbPoints() << endl;
    cout << "-------------------------------------------" << endl;

    return EXIT_SUCCESS;
}