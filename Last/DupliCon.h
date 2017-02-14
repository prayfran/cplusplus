#ifndef _SLINK_H_INCLUDED_
#define _SLINK_H_INCLUDED_

#include <cassert>
#include <iostream>

template <typename T, class Compare = std::less<T> >
class DupliCon {
  private:
    struct node {
	T data;
	struct node *next;
	int count;
    };
    node *head, *tail;
    
  public:
    typedef unsigned int size_type;
    typedef T key_type;
    typedef T value_type;
    class iterator {
      private:
	node *p;
	// This private ctor is for the container class only:
	friend class DupliCon;
	iterator(node *ptr) : p(ptr) { }
      public:
	iterator() : p(0) { }
	iterator &operator++() {	// Preincrement
	    assert(p);
	    p = p->next;
	    return *this;
	}
	iterator operator++(int) {	// Postincrement
	    const iterator tmp = *this;
	    ++*this;
	    return tmp;
	}
	// *iterator: Return a reference to the datum
	T &operator*() const {
	    assert(p);
	    return p->data;
	}
	// iterator->: Return the address of the datum
	T *operator->() const {
	    assert(p);
	    return &p->data;
	}
	bool operator==(const iterator &rhs) const {
	    return p==rhs.p;
	}
	bool operator!=(const iterator &rhs) const {
	    return !(*this == rhs);
	}
    };

    DupliCon() : head(0), tail(0) {
    }

    DupliCon (const DupliCon<value_type>& man)   
	{	
		node *v = this->head;
		node *b = man->head;	
		while(v->next != NULL){
			b = v;
			v=v->next;
		}
	}

    ~DupliCon() {
	clear();
    }

	template <typename iterator>
     DupliCon (const iterator start, const iterator finish): DupliCon(){  
     insert(start, finish);
     }

    void clear() {
	while (head) {
	    node *p = head->next;
	    delete head;
	    head = p;
	}
    }

   
    bool empty() const {
	return !head;
    }
	
    void insert(const value_type &man){
		int flag = 0;
		if(head == NULL){
		head = new node;
		head->data = '0';
		head->next = NULL;
		}
		if(tail == NULL){
		tail = new node;
		tail->data = '0';
		tail->next = NULL;
		}
		node *v = head;
		while(v->next != NULL){
			if((!Compare()(v->data, man)) && (!Compare()(man, v->data))){
			v->count = v->count + 1;
			}
			v = v->next;
		}
		
		 node *p = new node;
		 p->data = man;
		 p->next = NULL;
		for (node *v = head; v; v=v->next){
					
		if(v->next != NULL){
		if(Compare()(p->data, v->next->data)){
			node *temp = v;
			temp->data = man;
			p->next = temp;
			temp->next = p->next->next;
			return;
				}
			}else{
			
			v->next = p;
				return;	}
		}
		
		
	}

    template <typename iterator>
   void insert(iterator ty, iterator blah){
	
	while(ty != blah){
		
		this->insert(*ty);
		++ty;			
		}
	
	}
	
    size_type erase(const value_type boom){
	size_type count =0;
	for (node *p = head; p; p=p->next){
		if(head->data == boom){
			count++;
		}
	}
	return count;
	}

    void erase(iterator yea){
	for (node *p = head; p; p=p->next){
	   if(p == yea){
		erase(p->data);
		}
	    }
	}

    
    size_type size() const {
	int count=0;
	for (node *p = head; p; p=p->next){
	    count++;
	    if(head->count != 0){
	        count + head->count;
		count--;
	    }
	}
	return count;
    }

	value_type max_size(){

	return sizeof(this);
	}
    int unique_size(){
	int uniquecount = 0;
	int size = this->size();
	int flags = 0;
	 	for (node *p = head; p; p=p->next){
			int flags = 0;
			for (node *v = head; v; v=v->next){
				if((!Compare()(v->data, p->data)) && (!Compare()(p->data, v->data)))
				flags++;
		}
		if(flags == 1){
		uniquecount++;
		}
		}
	
	return uniquecount+1;
	}

    iterator find(const value_type &man){
	for (node *p = head; p; p=p->next){
	     
	    if(p->data == man){
		return p;
		}
	    }
	return end();
	}



    iterator begin() const {
	return head;
    }

    iterator end() const {
	return 0;
    }
	
    value_type count(const value_type man){
	
	value_type fcount;
	for (node *p = head; p; p=p->next){
	    if(p->data == man){
		fcount++;
		}
	    }
	return fcount;
    }
    

};

#endif /* _SLINK_H_INCLUDED_ */

