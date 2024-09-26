#include <iostream>
using namespace std;

template <class T>
struct nodo {
	T valor[5];
	nodo<T>* next;
	T* top;
	int tam;
    nodo(nodo<T>* n = nullptr){
        next = n;     
        top=valor;
		tam=0;
    }
};

template <class T>
struct ls {
	nodo<T>* head=nullptr;
	void add(T v);
	//void del(T v);
	bool find(T v, nodo<T>*& pos, T*&pos_v);
	void print();
};

template<class T>
void ls<T>::add(T v) {
    nodo<T>*p;
	T*p_v;
	if(!find(v,p,p_v)){
		cout << "insertar " << v << endl;
		if(p==nullptr){
			head=new nodo<T>(head);
			*(head->valor)=v;
			head->tam++;
		}else{
			if(p->tam!=5){
				if(p_v>p->top){
					*(p_v)=v;
					p->top++;
					p->tam++;
				}else{
					T*tmp=p->top;
					while(tmp>=p_v){
						*(tmp+1)=*tmp;
						tmp--;
					}
					*p_v=v;
					p->top++;
					p->tam++;
				}
			}else{
				int tmp_v=*(p->top);
				T*tmp=p->top;
				while(tmp>=p_v){
					*(tmp+1)=*tmp;
					tmp--;
				}
				*p_v=v;
				if(!p->next){
					p->next=new nodo<T>(p->next);
					*(p->next->valor)=tmp_v;
					p->next->tam++;
				}
			}
		}
	}else{
		cout << v <<  " elemento repetido" << endl;
	}
}

/*
template<class T>
void ls<T>::del(T v) {

}*/

template<class T>
bool ls<T>::find(T v, nodo<T>*&pos, T*&pos_v) {
	pos=head;
	while(pos){
		pos_v=pos->valor;
		for(;pos_v <= pos->top && v > *(pos_v);pos_v++);
		if(v==pos_v){
			return true;
		}else if(pos_v>pos->top){
			if(!pos->next){
				return false;
			}else{
				pos=pos->next;
			}
		}
	}
	return false;
	/*for(;pos;pos=pos->next){
		pos_v=pos->valor;
		for(;pos_v <= pos->top && v > *(pos_v);pos_v++);
		if(v==*(pos_v)){
			return true;
		}else if(pos_v>pos->top && !pos->next){
			return false;
		}
		return false;
	}
	return false;*/
}

template<class T>
void ls<T>::print() {
	nodo<T>* p = head;
	while(p){
        cout << "[ ";
		T*q=p->valor;
		if(p->valor==p->top && p->tam==0){
			cout << "- - - - - ";
		}else{
			int cont=0;
			for(;q<=p->top;q++,cont++){
				cout << *q << " ";
			}
			while(cont<5){cout << "- ";cont++;}
		}
        p=p->next;
        cout << "] -> ";
    }
}

int main() {
	ls<int>l1;
	l1.print();
    l1.add(5);
	l1.print();
	l1.add(7);
	l1.print();
	l1.add(3);
	l1.print();
	l1.add(6);
	l1.print();
	l1.add(0);
	l1.print();
	l1.add(2);
	l1.print();
	l1.add(-1);
	l1.print();
	return 0;
}