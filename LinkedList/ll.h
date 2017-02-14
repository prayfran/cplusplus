#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_ 

using namespace std;

class LinkedList {
  public:
      LinkedList();
      LinkedList(unsigned int uiData, Link *pNext);
    void print(std::ostream& os );
    void Initialize();
    bool Insert(unsigned int uiData);
    bool Delete(unsigned int *pData);
    //friend ostream& operator<<(ostream& os, LinkedList& obj);
  private:
    struct Link {
	unsigned int m_uiData;
	Link* m_pNext;
	void Initialize (unsigned int uiData, Link *pNext);
    } *m_pHead;
};

#endif /* _LINKED_LIST_H_ */ 
