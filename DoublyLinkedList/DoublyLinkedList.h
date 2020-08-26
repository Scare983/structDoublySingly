#include "ItemType.h"

struct NodeType {
	ItemType data;
	NodeType *next;
	NodeType *back;
	
};


class DoublyLinkedList {
	public: 
		
		DoublyLinkedList();
		bool isEmpty();
		~DoublyLinkedList();
		void insertItem(ItemType &item);
		void deleteItem(ItemType &item);
		int lengthIs() const;
		void print();
		void additivePairs(ItemType& item);
	private:
		
		int length;
		NodeType *head;
		NodeType *current;
	
	
};