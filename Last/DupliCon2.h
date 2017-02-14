/*
Parker Franks
04-30-2014
CS253
DupliCon
*/
#ifndef DupliCon_include
#define DupliCon_include


#include <iostream>




template <typename T>
class ListNode //nodes to be contained with a list
{

public:
	ListNode(T);
	T getData();
	T data; //templatized data stored in node
	ListNode* nextPtr; //pointer to the next node in list
	

	
	ListNode(const T dataIn)
	{
	data = dataIn; //stores data in node
	nextPtr = 0; //initializes point to next node to null
	}



	getData() //returns data stored in node
	{
	return data;
	}

};



template <typename T>
class ListIter{
public:
	
	ListNode<T> curr;
	ListNode<T>* p(0);
	
	bool hasNext(ListNode<T> ha){
	ListIter<T>::curr = ha;
	if(ha.nextPtr != NULL){
		return true;
		ha.nextPtr = ha.nextPtr.nextPtr; 
	}
	return false;
	}


	bool operator!=(const ListIter<T> &rhs) const{
	return !(*this == rhs);
	}

	ListIter operator++(){
	assert(p);
	p = p->nextPtr;
	return *this;
	}

	T operator* ()const{
	assert(p);
	return p->data;
	}
};

template <typename Batman, typename Joker = std::less<Batman> >
class DupliCon{

public:
typedef size_t size_type;
typedef Batman value_type;
typedef Batman iterator;
const value_type ne;
const value_type nex;
ListNode<value_type> head = new ListNode<value_type>(ne);


DupliCon (): head(0){               //Ra's Al Ghul

}


template <typename iterator>
DupliCon (const iterator start, const iterator finish): DupliCon(){  //Nightwing is a Batman Constructor that takes iterators
     insert(start, finish);
     sort();
}

DupliCon (const DupliCon<value_type>& man)   //Because He's Batman
{
	ListIter<value_type> iter = new ListIter<value_type>();
	while(iter.hasNext(man) == true){
		this.insert(iter.curr);
	}	

}

~DupliCon (){				//Joker
 this->clear(); 

}

ListIter<Batman> begin(){                           //Bruce Wayne
	return head;
}

ListIter<Batman> end(){				//Batman
	return 0;
}

bool empty(){				//Bruce's Dead Family
	return head.nextPtr == NULL;
}

int size(){				//Bruce's Wallet
	ListIter<value_type> iter = new ListIter<value_type>();
	int count = 0;
	while(iter.hasNext(this) == true){
		count++;
	}
	return count;
}

int unique_size(){
	int uniquecount = 0;
	value_type curr;
	ListIter<value_type> iter = new ListIter<value_type>();
	while(iter.hasNext(this) == true){
		iter.curr = this.data;
	 	for(int i =0; i< this.size(); i++){
		     if(Joker()(iter.curr -> iter.curr.nextPtr, iter.curr.nextPtr )){
				uniquecount++;
			}
		}
	}
	return uniquecount;
}

value_type max_size(){

	return sizeof(this);

}

ListIter<value_type> find(const value_type man){
	ListIter<value_type> iter = new ListIter<value_type>();
	while(iter.hasNext(this) == true){
		if(this.data == man){
		return iter;
		}
	}
	return end();
}


value_type count(const value_type man){
	ListIter<value_type> iter = new ListIter<value_type>();
	value_type count;
	while(iter.hasNext(this) == true){
		if(this.data == man){
		count++;
		}
	}
	return count;
}

void insert(const value_type man){
	ListIter<value_type> iter = new ListIter<value_type>();
	while(iter.hasNext(this) == true){
		if(this.data == man){
		break;
		}
		if(this.data < man){
			man.nextPtr = this.nextPtr.nextPtr;
			this.nextPtr = man;
		}
	}
	sort();

}

template <typename iterator>
void insert(iterator ty, iterator blah){
	while(ty.hasNext(this) == true){
		if(this != blah.curr){
		this.insert(ty.curr);	
		}else{
			break;
		}			
		}
	sort();
	}

size_type erase(const value_type boom){
	ListIter<value_type> iter = new ListIter<value_type>();
	size_type count =0;
	while(iter.hasNext(this) == true){
		if(iter.curr.nextPtr.data == boom){
			count++;
			this.nextPtr == this.nextPtr.nextPtr;
		}
	}
	sort();
	return count;
}

void erase(ListIter<value_type> yea){
	ListIter<value_type> iter = new ListIter<value_type>();
	while(iter.hasNext(this) == true){
		if(iter.curr.nextPrt == yea.curr){
			this.nextPtr == this.nextPtr.nextPtr;
		}
	}
	sort();

}

void clear(){
	ListIter<value_type> iter = new ListIter<value_type>();
	while(iter.hasNext(this) == true){
		erase(iter.curr);
	}


}

void sort(){
	ListIter<value_type> iter = new ListIter<value_type>();
	while(iter.hasNext(this) == true){
		if(this->nextPtr->data > this->nextPtr->nextPtr->data){
			ListNode<value_type> temp = this.nextPtr;
			this.nextPtr == this.nextPtr.nextPtr;
			this.erase(this.nextPtr);
			this.nextPtr.nexPtr = temp;
			
		}
	}
}

};

#endif 
