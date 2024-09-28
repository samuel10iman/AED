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
	void del(T v);
	bool find(T v, nodo<T>*& pos, T*&pos_v);
	void print();
};

template<class T>
void ls<T>::add(T v) {
	nodo<T>*p;
	T* pv;
	if(!find(v,p,pv)){
		cout << "insertar " << v << endl;
		if(p==nullptr){
			head=new nodo<T>(head);
			*(head->valor)=v;
			head->tam++;
		}else{
			T vop=*p->top;
			while(p){
				T*tmp=p->top;
				while(tmp>=pv){
					*(tmp+1)=*tmp;
					tmp--;
				}
				*pv=v;
				if(p->tam==5){
					if(!p->next){
						p->next=new nodo<T>(p->next);
						*(p->next->valor)=vop;
						p->next->tam++;
						p=p->next;
						return;
					}else{
						v=vop;
						p=p->next;
						pv=p->valor;
					}
				}else{
					p->top++;
					p->tam++;
					p=p->next;
				}
			}
		}
	}else{
		cout << v << " repetido" << endl;
	}
}


template<class T>
void ls<T>::del(T v) {
	nodo<T>*p;
	T* pv;
	if(find(v,p,pv)){
		cout << "eliminando " << v << endl;
		T temp;
		T* tmp=pv;
		while(p){
			while(tmp<p->top){
				*tmp=*(tmp+1);
				tmp++;
			}
			if(!p->next){
				p->top--;
				p->tam--;
				return;
			}
			if(p->next->tam==1){
				if(!p->next){
					head=nullptr;
					delete p;
				}else{
					*p->top=*p->valor;
					nodo<T>*q=p->next;
					p->next=nullptr;
					delete q;
				}
				return;
			}
			*p->top=*p->next->valor;
			tmp=p->next->valor;
			p=p->next;
		}
	}else{
		cout << "no existe elemento " << v << endl;
	}
}

template<class T>
bool ls<T>::find(T v, nodo<T>*&pos, T*&pos_v) {
	pos=head;
	while(pos){
		pos_v=pos->valor;
		for(;pos_v <= pos->top && v > *(pos_v);pos_v++);
		if(v==*pos_v){
			return true;
		}else if(pos_v>pos->top){
			if(!pos->next){
				return false;
			}else{
				pos=pos->next;
				continue;
			}
		}
		return false;
	}
	return false;
}

template<class T>
void ls<T>::print() {
	nodo<T>* p = head;
	cout << "HEAD -> ";
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
	cout << " NULL" << endl;
}

int main() {
	ls<int>l1;
	l1.print();
    l1.add(9);
	l1.print();
	l1.add(8);
	l1.print();
	l1.add(3);
	l1.print();
	l1.add(6);
	l1.print();
	l1.add(0);
	l1.print();
	l1.add(4);
	l1.print();
	l1.add(-1);
	l1.print();
	l1.add(2);
	l1.print();
	l1.add(7);
	l1.print();
	l1.add(10);
	l1.print();
	l1.del(10);
	l1.print();
	l1.del(7);
	l1.print();
	l1.del(2);
	l1.print();
	l1.del(0);
	l1.print();
	l1.del(3);
	l1.print();
	/*l1.del(8);
	l1.print();
	l1.del(9);
	l1.print();
	l1.del(6);
	l1.print();
	l1.del(3);
	l1.print();*/
	return 0;
}