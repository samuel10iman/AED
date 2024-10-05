#include <iostream>
using namespace std;

template <class T>
struct nodo{
    T valor;
    nodo<T>* next;
    nodo(T v, nodo<T>*n=nullptr){
        valor=v;
        next=n;
    }
};

template<class T>
class pila{
    public:
    nodo<T>* top=nullptr;
    void push(T valor);
    bool pop(T& valor);
    void print();
};

template <class T>
void pila<T>::push(T valor){
    top=new nodo<T>(valor,top);
}

template <class T>
bool pila<T>::pop(T & valor){
    nodo<T>*p=top;
    if(!p){
        return false;
    }else{
        valor=top->valor;
        top=p->next;
        p=nullptr;
        delete p;
        return true;
    }
}

template <class T>
void pila<T>::print(){
    nodo<T>* p=top;
    cout << "TOP-> ";
    while(p){
        cout << p->valor << "->";
        p=p->next;
    }
    cout << "NULL" << endl;
}

int main(){
    pila<int> p1;
    p1.print();
    for(int i=0;i < 5;i++){
        p1.push(i);
        p1.print();
    }
    int v_elim;
    for(int i=0;i < 6;i++){
        if(p1.pop(v_elim)){
            cout << "eliminando " << v_elim << endl;
        }else{
            cout << "pila vacia" << endl;
        }
        p1.print();
    }
    return 0;
}