#include <vector>

using namespace std;

void my_push_back(vector<int>& v, int value){
    v.resize(v.size()+1,value);
}
void my_pop_back(vector<int>& v){
    v.resize(v.size()-1);
}
void my_resize(vector<int>& v, size_t size, int value = 0){
  while(size != v.size()){
        if(size > v.size()){
            my_push_back(v,value);
        } else if (size < v.size()){
            my_pop_back(v);
        }
    }
}

int main() {
    vector<int> v{1, 2, 3, 4, 5, 6};
    my_push_back(v, 7);     // v contient {1, 2, 3, 4, 5, 6, 7}
    my_pop_back(v);         // v contient {1, 2, 3, 4, 5, 6}
    my_pop_back(v);         // v contient {1, 2, 3, 4, 5}
    my_resize(v,3);         // v contient {1, 2, 3}
    my_resize(v,5,1);       // v contient {1, 2, 3, 1, 1}
    my_resize(v,8);         // v contient {1, 2, 3, 1, 1, 0, 0, 0}

    return 0;
}