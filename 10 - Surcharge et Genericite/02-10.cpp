#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

template <typename T, size_t taille>
using Ligne = array<T, taille>;

template <typename T, size_t nb_ligne, size_t nb_colonne>
using Matrice = array<Ligne<T, nb_colonne>, nb_ligne>;

template <typename T1, size_t nb_ligne, size_t nb_colonne>
T1 sum1(const Matrice<T1, nb_ligne, nb_colonne>& matrice) {
    T1 sum = T1();
    for (const array<T1, nb_colonne>& l : matrice) {
        for (const T1& e : l) {
            sum += e;
        }
    }
    return sum;
}

template <typename T1, size_t nb_ligne, size_t nb_colonne>
T1 sum2(const Matrice<T1, nb_ligne, nb_colonne>& matrice) {
    T1 sum = T1();
    for (size_t i = 0; i < nb_ligne; ++i) {
        for (size_t j = 0; j < nb_colonne; ++j) {
            sum += matrice[i][j];
        }
    }
    return sum;
}

template <typename T, typename FN>
void print_for_all(const vector<T>& v, FN fct ){
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) cout << ", ";
        cout << fixed << setprecision(1) << fct(v[i]);
    }
    cout << "]" << endl;
}

int main(){
    using Matrice_int_2x3      = Matrice<int,    2, 3>;
    using Matrice_double_3x2   = Matrice<double, 3, 2>;

    Matrice_int_2x3 m1      {{{ 0,  1,  2},
                              {10, 11, 12}}};

    Matrice_double_3x2 m2   {{{0.0, 1.1},
                              {1.0, 1.1},
                              {2.0, 2.1}}};

    cout << sum1(m1) << endl;
    cout << sum1(m2) << endl;

    cout << sum2(m1) << endl;
    cout << sum2(m2) << endl;
}