#include <cstdlib>
#include "ll.h" 

using namespace std;
LinkedList::LinkedList(unsigned int uiData, Link *pNext)
{
 m_uiData = uiData;
    m_pNext = pNext;
}

LinkedList::LinkedList()
{
 m_pHead = NULL;
}

bool LinkedList::Insert (unsigned int uiData) {
    Link* new_link = new Link;

    new_link->Initialize (uiData, m_pHead);
    m_pHead = new_link;

    return true;
}
void LinkedList:: print(std::ostream& os ){
	link *top = m_pHead;
	while(tmp != Null){
		os<< "Element: "<< tmp->m_uiData<<endl;

		tmp =tmp->m_pNext;
		
	}


}
/*
ostream& operator<<(ostream& os, LinkedList& obj)
{
	obj.print();

	return os;
}*/

bool LinkedList::Delete (unsigned int &Data) {

    bool ret_val = false;

    if (m_pHead != NULL) {
	Link *temp = m_pHead;
	m_pHead = m_pHead->m_pNext;
	Data = temp->m_uiData;
	delete temp;
	ret_val = true;
    }

    return ret_val;

}
