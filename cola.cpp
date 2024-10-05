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

template <class T>
class cola{
    public:
    nodo<T>* head =nullptr;
    nodo<T>* tail =nullptr;
    void push(T valor);
    bool pop(T& valor);
    void print();
};

template<class T>
void cola<T>::push(T valor){
    if(!head){
        tail=new nodo<T>(valor);
        head=tail;
    }else{
        tail->next=new nodo<T>(valor);
        tail=tail->next;
    }
}

template <class T>
bool cola<T>::pop(T& valor){
    if(!head){
        return false;
    }else{
        valor=head->valor;
        nodo<T>*p=head;
        head=head->next;
        delete p;
        return true;
    }
}

template<class T>
void cola<T>::print(){
    nodo<T>*p=head;
    cout << "HEAD-> ";
    for(;p;p=p->next){cout << p->valor << "->";}
    cout << " <- TAIL" << endl;
}

int main(){
    cola<int> c1;
    c1.print();
    for(int i=0;i<6;i++){
        c1.push(i);
        c1.print();
    }
    int v_elim;
    for(int i=0;i<7;i++){
        if(c1.pop(v_elim)){
            cout << "eliminando " << v_elim << endl;
        }else{
            cout << "cola vacia" << endl;
        }
        c1.print();
    }
    return 0;
}