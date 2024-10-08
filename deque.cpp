#include <iostream>
using namespace std;

class deque{
    public:
    int** map;
    int size_map, size_vec;
    //void push_back(int v);
    //void pop_back(int v);
    //void push_front(int v);
    //void push_front(int v);
    //void print();
    deque(int size_map, int size_vec);
};

deque::deque(int sm, int sv){
    size_map=sm;
    size_vec=sv;
    int inim=size_map/2;
    map=new int*[size_map];
    int **p_map=map+inim;
    int **ini_map=map;
    int **fin_map=map+size_map;
}

int main(){
    deque d1(5,5);
    return 0;
}