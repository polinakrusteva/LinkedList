#ifndef LIST
#define LIST
#include "Node.h"

template <typename T>
class List
{
public:
	List();
	
	List(const List&);
	
	~List();
	
	void push_front(const T& val);
	
	void push_back(const T& val);
	
	void pop_front();
	
	void pop_back();
	
	T front();
	
	T back();
	
	int get_size() const;
	
	void clear();
	
	bool empty();
	
	class iterator{
	public:
		iterator(Node<T>*);
		T operator*();
		iterator operator++();
		iterator operator++(int);
		bool operator!=(iterator);
		Node<T>* getCurrent();
		void setCurrent(Node<T>*);
	private:
		Node<T>* current;
	};
	iterator begin() const;
	iterator end() const;
	void insert(iterator&, const T&);
	void erase(iterator&);
private:
	Node<T>* pFront;
	Node<T>* pBack;
	int size;
};

template <typename T>
List<T>::iterator::iterator(Node<T>* node)
{
	this->current = node;
}

template <typename T>
T List<T>::iterator::operator*()
{
	return this->current->getVal();
}

template <typename T>
typename List<T>::iterator List<T>::iterator::operator++()
{
	this->current = this->current->getNext();
	return *this;
}

template <typename T>
typename List<T>::iterator List<T>::iterator::operator++(int value)
{
	this->current = this->current->getNext();
	return *this;	
}

template <typename T>
bool typename List<T>::iterator::operator!=(typename List<T>::iterator other)
{
	return (this->current->getNext() != other.getCurrent()->getNext() && this->current->getPrevious() != other.getCurrent()->getPrevious());
}

template <typename T>
Node<T>* List<T>::iterator::getCurrent()
{
	return this->current;
}

template <typename T>
void List<T>::iterator::setCurrent(Node<T>* node){
	this->current = node;
}

template <typename T>
List<T>::List()
{
	this->pBack = NULL;
	this->pFront = NULL;
}

template<typename T>
List<T>::List(const List<T>& other)
{
	this->pFront = other.begin().getCurrent();
	this->pBack = other.end().getCurrent()->getPrevious();
	this->size = other.get_size();
	List<T>::iterator iter(other.begin().getCurrent());
	while (iter != other.end())
	{
		iter++;
		this->push_back(iter.getCurrent()->getVal());
	}
}

template <typename T>
List<T>::~List()
{
	List<T>::iterator iter = this->begin();
	while (iter != this->end())
	{
		delete iter.getCurrent();
	}
	delete iter.getCurrent();
}

template <typename T>
void List<T>::push_front(const T& value)
{
	if (size == 0)
	{
		this->pBack = new Node<T>(value, NULL, NULL);
		this->pFront = this->pBack;
	}
	else{
		Node<T>* temp = new Node<T>(value, NULL, this->pFront);
		this->pFront->SetPrevious(temp);
		this->pFront = temp;
	}
	size++;
}

template <typename T>
void List<T>::push_back(const T& value)
{
	if (size == 0)
	{
		this->pBack = new Node<T>(value, NULL, NULL);
		this->pFront = this->pBack;
	}
	else{
		Node<T>* temp = new Node<T>(value, this->pBack, NULL);
		this->pBack->SetNext(temp);
		this->pBack = temp;
	}
	size++;
}

template <typename T>
void List<T>::pop_front()
{
	if (this->size != 0)
	{
		Node<T>* temp = this->pFront;
		this->pFront = this->pFront->getNext();
		delete temp;
	}
}

template <typename T>
void List<T>::pop_back()
{
	if (this->size != 0)
	{
		Node<T>* temp = this->pBack;
		this->pBack = this->pBack->getPrevious();
		delete temp;
	}
}

template <typename T>
T List<T>::front()
{
	return this->pFront->getVal();
}

template <typename T>
T List<T>::back()
{
	return this->pBack->getVal();
}

template <typename T>
void List<T>::clear()
{
	delete this;
}

template <typename T>
int List<T>::get_size() const
{
	return this->size;
}

template <typename T>
bool List<T>::empty()
{
	return this->size == 0;
}

template <typename T>
typename List<T>::iterator List<T>::begin() const
{
	return iterator(this->pFront);
}

template <typename T>
typename List<T>::iterator List<T>::end() const
{
	T val;
	Node<T>* endNode = new Node<T>(val, this->pBack, NULL);
	this->pBack->SetNext(endNode);
	return iterator(endNode);
}

template <typename T>
void List<T>::insert(typename List<T>::iterator& iter, const T& val) {
	Node<T>* insertionNode = new Node<T>(val, NULL, NULL);
	if (iter.getCurrent()->getPrevious() == NULL) {
		iter.getCurrent()->SetPrevious(insertionNode);
		insertionNode->SetNext(iter.getCurrent());
		this->pFront = insertionNode;
	}

	else if (iter.getCurrent()->getNext() == NULL) {
		iter.getCurrent()->SetNext(insertionNode);
		insertionNode->SetPrevious(iter.getCurrent());
		this->pBack = insertionNode;
	}
	else {
		Node<T>* prev = iter.getCurrent()->getPrevious();
		iter.getCurrent()->SetPrevious(insertionNode);
		prev->SetNext(insertionNode);
		insertionNode->SetNext(iter.getCurrent());
		insertionNode->SetPrevious(prev);
	}
	iter.setCurrent(insertionNode);
	this->size++;
}

template<typename T>
void List<T>::erase(typename List<T>::iterator& iter){
	if (iter.getCurrent()->getPrevious() == NULL){
		iter.setCurrent(iter.getCurrent()->getNext());
		iter.getCurrent()->SetPrevious(NULL);
		this->pFront = iter.getCurrent();
	}
	else if (iter.getCurrent()->getNext() == NULL){
		iter.setCurrent(iter.getCurrent()->getPrevious());
		iter.getCurrent()->SetNext(NULL);
		this->pBack = iter.getCurrent();
	}
	else{
		iter.getCurrent()->getPrevious()->SetNext(iter.getCurrent()->getNext());
		iter.getCurrent()->getNext()->SetPrevious(iter.getCurrent()->getPrevious());
		Node<T>* temp = iter.getCurrent()->getNext();
		delete iter.getCurrent();
		iter.setCurrent(temp);
	}
	this->size--;
}
#endif
