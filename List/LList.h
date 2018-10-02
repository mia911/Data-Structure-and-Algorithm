#ifndef LLIST_H
#define LLIST_H

/*
	Linked List class that store integers, with iterator.
	Minh Doan
	September 2015
*/
#include <ostream>
#include <stdexcept>

using namespace std;

template <class T>
struct node_t {
  T data;
  node_t* next;
};


template <class T> class LListIterator;


template <class T>
class LList{

  public:
  LList(){
    head = NULL;
    tail = NULL;
    the_size = 0;
  }
  
  ~LList(){
		clear();
	}
	
  LList(const LList& other){
  	head = NULL;
		tail = NULL;
		the_size = 0;
		if(other.head == NULL || other.tail == NULL){
			return;
		}
		node_t<T>* temp = other.head;
		while(temp){
			push_back(temp->data);
			temp = temp->next;
		}
  }
	
  LList<T>& operator= (const LList& other){  
		if(this == &other){
			return *this;
		}
  	clear();
		if(other.head == NULL || other.tail == NULL){
			return *this;
		}
		node_t<T>* temp = other.head;
		while(temp){
			push_back(temp->data);
			temp = temp->next;
		}
		return *this;
	}
     
  T getAt(int pos) const{
		if(pos < 0){
			pos = pos + the_size;	
		}
		if(pos < 0){
			throw logic_error("Index too negative");
		}
    node_t<T>* temp = head;
    while(temp != NULL && pos > 0){
      temp = temp->next;
      pos--;
    }
    if(pos == 0 && temp !=NULL){
      return temp->data;
    }
    throw logic_error("Index invalid");
  }

  unsigned int size() const{
    return the_size;
  }
 
  void push_back(T value){
    if(head == NULL || tail == NULL){
      push_front(value);
    }else{
      node_t<T>* temp = new node_t<T>;
      temp->data = value;
      temp->next = NULL;
      tail->next = temp;
      tail = temp;
      the_size++;
    }
  }
  void push_front(T value){
    if(head == NULL || tail == NULL){
      head = new node_t<T>;
      head->data = value;
      head->next = NULL;
      tail = head;
      the_size = 1;
    }else{
      node_t<T>* temp = new node_t<T>;
      temp->data = value;
      temp->next = head;
      head = temp;
      the_size++;
    }
  }
	
	void setAt(T value, int pos){
		if(pos < 0){
			pos = pos + the_size;	
		}
		if(pos < 0){
			throw logic_error("Index too negative");
		}
		node_t<T>* temp = head;
    while(temp != NULL && pos > 0){
      temp = temp->next;
      pos--;
    }
    if(pos == 0 && temp !=NULL){
    	temp->data = value;
			return;
    }
    throw logic_error("Index invalid");
  }
	
	void remove(int pos){
		if(pos < 0){
			pos = pos + the_size;	
		}
		if(pos < 0){
			throw logic_error("Index too negative");
		}
		if(pos >= the_size){
			throw logic_error("Index invalid");
		}
		if(pos == 0 and the_size == 1){
			delete head;
			head = NULL;
			tail = NULL;
			the_size = 0;
		}else if(pos == 0){ 
			node_t<T>* temp = head;
			head = head->next;
			delete temp;
			the_size--;
			return;
		}else if(pos == the_size-1){ 
			node_t<T>* temp = head;
	    while(temp->next != tail ){
	      temp = temp->next;
	    }
			node_t<T>* to_delete = temp->next;
			tail = temp;
			temp->next = NULL;
			delete to_delete;
			the_size--;
		}else{ 
			pos = pos - 1;
			node_t<T>* temp = head;
	    while(temp != NULL && pos > 0){
	      temp = temp->next;
	      pos--;
	    }
	    if(pos == 0 && temp !=NULL){
				node_t<T>* to_delete = temp->next;
				temp->next = to_delete->next;
				delete to_delete;
				the_size--;
				return;
	    }
	    throw logic_error("Index invalid");
		}
	}
	
	LList<T> reverse() const{
		LList<T> ret;
		node_t<T>* temp = head;
		while(temp){
			ret.push_front(temp->data);
			temp = temp->next;
		}
		return ret;
	}
	
	LList<T> operator+(const LList<T>& other) const{
		LList<T> ret;
		node_t<T>* temp = head;
		while(temp){
			ret.push_back(temp->data);
			temp = temp->next;
		}
		temp = other.head;
		while(temp){
			ret.push_back(temp->data);
			temp = temp->next;
		}
		return ret;
	}
	
	bool operator==(const LList<T>& other) const{
		if(the_size != other.the_size){
			return false;
		}
		node_t<T>* temp1 = head;
		node_t<T>* temp2 = other.head;
		while(temp1 && temp2){
			if(temp1->data != temp2->data){
				return false; 
			}
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		if(temp1 != temp2){ 
			return false;
		}
		return true;
	}
	
	bool operator!=(const LList<T>& other) const{
		return ! operator==(other);
	}
	
	void clear(){
		node_t<T>* last = head;
		while(head){
			head = head->next;
			delete last;
			last = head;
		}
		head = NULL;
		tail = NULL;
		the_size = 0;
	}
 
  LListIterator<T> begin() const{ 
    LListIterator<T> ret;
    ret.current = head;
    ret.parent = this;
    return ret;
  }
  
  LListIterator<T> end() const{
    LListIterator<T> ret;
    ret.current = NULL;
    ret.parent = this;
    return ret;
  }
  
  private:
  node_t<T>* head;
  node_t<T>* tail;
  
  unsigned int the_size;
};

template <class T>
class LListIterator{
  friend LList<T>; 
  public:
  LListIterator<T> next(){
    if(current){  
      current = current->next;
    }
    return *this;
  }
  
  LListIterator<T> operator++(int steps){
     return next();
  }
  
  T get(){
    if(!current){
      throw logic_error("Iterator not valid");
    }
    return current->data;
  }
  
  T operator*(){
    return get();
  }
  
  bool operator!=(const LListIterator<T>& other){
    if( parent != other.parent){
      return true;
    }
    return current != other.current;
  }
  
  private:
  node_t<T>* current;
  const LList<T>* parent; 
};

template <class T>
ostream& operator<<(ostream& out, const LList<T> other){
	out << "[";
	if(other.size() > 0){
	  out << other.getAt(0);
	}
	for(LListIterator<T> i = other.begin().next(); i != other.end(); i++){
		out << ", " << *i;
	}

	out << "]";
	return out;
}


#endif
