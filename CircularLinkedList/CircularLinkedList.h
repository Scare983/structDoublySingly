#include "ItemType.h"

struct NodeType {
	ItemType data;
	NodeType *next;
	
};


class CircularLinkedList {
	public: 
		
		CircularLinkedList();
		bool isEmpty();
		~CircularLinkedList();
		void insertItem(ItemType &item);
		void deleteItem(ItemType &item);
		int lengthIs() const;
		void print();
	
	private:
		
		int length;
		NodeType *head;
		NodeType *current;
	
	
};