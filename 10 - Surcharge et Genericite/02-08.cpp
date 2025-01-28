#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
T sum(const vector<T>& v) {
    T sum = 0;
    for (const auto& x : v) {
        sum += x;
    }
    return sum;
}

template <typename T>
T avg(const vector<T>& v) {
    return sum(v) / v.size();
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
    using Data    = double;
    using Ligne   = vector<Data>;
    using Matrice = vector<Ligne>;

    const Matrice notes {{4.0, 5.0, 6.0},  // Jean
                         {4.1, 5.1, 4.8},  // Marie
                         {3.5, 4.1     },  // Joshua
                         {4.5, 4.5, 4.6}}; // Ali

    cout << "somme   : " ;
    print_for_all(notes, sum<double>);
    cout << "moyenne : " ;
    print_for_all(notes, avg<double>);
}