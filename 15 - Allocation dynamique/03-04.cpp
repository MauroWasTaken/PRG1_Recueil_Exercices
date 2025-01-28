//
// Created by mauro on 20/01/25.
//

#include <iostream>
#include <stdexcept>

using namespace std;
template <typename T, size_t N>
class Tab {
public:
    Tab(){ data = new T[N]; }
    ~Tab() { delete[] this->data; }
    T& at(size_t i) { return data[i]; }
    [[nodiscard]] const T& at(size_t i) const {
        if (i >= N) throw out_of_range ("Tab::at");
        return data[i];
    }
    [[nodiscard]] size_t size() const { return N; }
    T& operator [](size_t i){ return data[i];}
    const T& operator [](size_t i) const{ return data[i];}
private:
    T* data;
};
template <typename T, size_t N>
ostream& operator <<(ostream& os, const Tab<T, N>& tab){
    os << "[";
    for(size_t i = 0; i < N; ++i){
        if(i) os << ", ";
        os << tab[i];
    }
    os <<"]";
    return os;
}

int main() {

    const size_t N = 3;

    try {
        cout << "------------" << endl;
        cout << "   tab1     " << endl;
        cout << "------------" << endl;
        Tab<int, N> tab1;
        for (size_t i = 0; i < N; ++i) {
            tab1.at(i) = (int) i;
        }
        cout << tab1 << endl;
        cout << "size : " << tab1.size() << endl;
        cout << endl;

        cout << "------------" << endl;
        cout << "   tab2     " << endl;
        cout << "------------" << endl;
        Tab<int, N> tab2;
        tab2 = tab1;
        cout << tab2 << endl;
        cout << "size : " << tab2.size() << endl;
        cout << endl;

        cout << "------------" << endl;
        cout << "   tab3     " << endl;
        cout << "------------" << endl;
        const Tab<int, N> tab3(tab1);
        cout << tab3 << endl;
        cout << "size : " << tab3.size() << endl;
        cout << endl;

        cout << "------------" << endl;
        cout << "   [] / at  " << endl;
        cout << "------------" << endl;
        cout << "tab1[0]     = 1; " << endl;
        tab1[0] = 1;
        cout << "tab1[0]     : " << tab1[0] << endl;
        cout << endl;
        cout << "tab1.at(1)  = 2; " << endl;
        tab1.at(2) = 2;
        cout << "tab1.at(1)  : " << tab1.at(2) << endl;

        try {
            cout << "tab1[3]     : " << tab1[3] << endl;
            cout << "tab3.at(3)  : " << tab3.at(3) << endl;
        }
        catch (out_of_range &e) {
            cout << "exception : " << e.what() << endl;
        }

        cout << endl;

    }
    catch (bad_alloc& e) {
        cout << e.what() << endl;
    }

    cout << endl;
    cout << "fin de programme" << endl;
    return EXIT_SUCCESS;
}