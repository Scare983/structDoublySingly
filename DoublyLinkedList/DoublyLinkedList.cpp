#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

DoublyLinkedList::DoublyLinkedList() {
	head = NULL;
	current = NULL;
	length = 0;
}
DoublyLinkedList::~DoublyLinkedList() {
	current = head;
		while(current != NULL) {
			NodeType *temp = current;
			current = current->next;
			temp->next = NULL;
			delete temp; 
			head = current;
		}
		current = NULL;
		delete head;
}
int DoublyLinkedList::lengthIs() const {
	return length;
}

void DoublyLinkedList::insertItem(ItemType &item) {
	NodeType *temp = new NodeType; //I FORGOT TO DYNAMICALLY allocate this. i need to learn gdb..
	temp->data = item;

		if(head == NULL) { //empty
			head = temp;
			length++;
		}
	
		else if(head->data.getValue() >= temp->data.getValue()) { //add to beggining
			if(head->data.getValue() == temp->data.getValue()) {
				cout << "Item " << item.getValue() << " exists and was not added" << endl; //special case of insert at beggining when already there
			}
			else {
				temp->next = head;
				
				temp->next->back = temp;
				head = temp;	
				length++;
			}
		}
		else {
			current = head;
			while(current->next != NULL && (current->next->data.getValue() <= temp->data.getValue())) {
							
				current = current->next;
				if(current->data.getValue() == item.getValue()) {
					cout << "Item " << item.getValue() << " exists and was not added" << endl; //case if item is already in list
					goto end;
				}	
			}
			
		 
			temp->next = current->next;
				if(temp->next != NULL ) {
					temp->next->back = temp;
				}
			
			current->next = temp;
			temp->back = current;
			
		length++;
		end:
		int j;

		}
		
		
		
} 
 

	

	

	
void DoublyLinkedList::deleteItem(ItemType &item) {
NodeType * deleteMe = new NodeType;
deleteMe = head;
bool found = false;
	while(deleteMe != NULL) {
		
	
	if(deleteMe->data.getValue() == item.getValue()) {
		found = true;
		if(deleteMe->data.getValue() == head->data.getValue()) {
			//cout << deleteMe->data.getValue() << "heefirst" << endl;
			
			head = deleteMe->next;
		
			
			
			
		}	
		 if(deleteMe->next != NULL) {
			
			deleteMe->next->back = deleteMe->back;
			
		}
		if(deleteMe->back != NULL) {
			deleteMe->back->next = deleteMe->next;
			//cout << deleteMe->back->data.getValue() << "heemid" << endl;
			//deleteMe->back->next = deleteMe->next;
		//	deleteMe->next->back = deleteMe->back;
		
			
	
		}
		
		
		
		
		//delete deleteMe;
		length--;
		break;
	}
	deleteMe = deleteMe->next;
		}
		free(deleteMe);
		deleteMe = NULL;
	
	if(!found) {
		cout << "Item " << item.getValue() << " does not exist in list" << endl;
	}
}

bool DoublyLinkedList::isEmpty() { //call whenever want to check if Head is null
	if(this->head == NULL) {
		
		return true;
	}
	else {
		return false;
	}
}
void DoublyLinkedList::print() {
	
NodeType* temp = head;
	if(length == 0) {
		cout << "List is empty!" << endl;
	}
	else {
		
  while(temp != NULL){
       ((temp->data).print());  //just printing value of a temp NodeType equal to the head
        temp = (temp->next);
   
    } 
	cout << endl;
	}
}
void DoublyLinkedList::additivePairs(ItemType &item) {
	int counter = 0;
	current = head;
	NodeType *temp;
	temp = head;
	NodeType *end;
	
		while(temp->next != NULL) {
			temp = temp->next;
			
		}
		end = temp;
		
	while(current->next != NULL) {
		while(temp->back != NULL) {
			if(current->data.getValue() + temp->data.getValue() == item.getValue()) {
				counter++;
				
				
		}
		temp = temp->back;
	}
	temp = end;
	current = current->next;
	}
	cout << endl;
		cout << "Possibilities: " << counter << endl;
int *pairs = new int[counter*2];
int i = 0;
end = temp;
current = head;
			while(current->next != NULL) {
				
		while(temp->back != NULL) {
			
			if(current->data.getValue() + temp->data.getValue() == item.getValue()) {
				pairs[i] = current->data.getValue();
				pairs[i+1] = temp->data.getValue();
				i++;
				i++;
				
		}
		temp = temp->back;
	}
	temp = end;
	current = current->next;
	}
	cout << "Pairs: ";
	for(int j =0; j < (sizeof(pairs)/sizeof(*pairs)); j++) {
		cout << "(" << pairs[j] <<"," << pairs[j++] << ") ";
	}
	cout << endl;
		}


	
