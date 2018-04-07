#include <iostream>
using namespace std;

template <class T>
class linked_list;

template <class T>
class node
{
	private:
		T dato;
		node<T> * p_next;
	
	public:
		node(const T & d, node<T> * n = NULL);
		virtual ~node(){}
		void print();
	
	friend class linked_list<T>;
};

template <class T>
class linked_list
{
	private:
		node<T> * p_head;
		node<T> * p_last;

	public:
		linked_list();
		virtual ~linked_list(){}
		void insert_front(const T & d);
		void insert_back(const T & d);
		void remove_front();
		void remove_back();
		void reverse();
		void print();
};

template<class T>
node<T>::node(const T & d, node<T> * n){
	dato = d;
	p_next = n;
}

template<class T>
void node<T>::print(){
	cout<<dato<<"->";
}

template<class T>
linked_list<T>::linked_list(){
	p_head=NULL;
	p_last=NULL;
}

template<class T>
void linked_list<T>::insert_front(const T & d){
	p_head=new node<T>(d,p_head);
	if(p_head->p_next==NULL) p_last=p_head;
}

template<class T>
void linked_list<T>::insert_back(const T & d){
	p_last->p_next=new node<T>(d);
	p_last=p_last->p_next;
}

template<class T>
void linked_list<T>::remove_front(){

}

template<class T>
void linked_list<T>::remove_back(){

}

template<class T>
void linked_list<T>::reverse(){
	node<T> *p_last=NULL;
	node<T> *p_next=NULL;
	node<T> *temp=p_head;
	while(temp){
		p_next=temp->p_next;
		temp->p_next=p_last;
		p_last=temp;
		temp=p_next;
	}
	p_head=p_last;
}

template<class T>
void linked_list<T>::print(){
	node<T> *aux=p_head;
	while(aux){
		aux->print();
		aux=aux->p_next;
	}
}

int main()
{
	linked_list<int> list_int;
	list_int.insert_front(3);
	list_int.insert_front(4);
	list_int.insert_front(5);
	list_int.print();
	cout<<endl;
	list_int.reverse();
	list_int.print();
	return 0;
}