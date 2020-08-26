#include "CircularLinkedList.h"
#include <iostream>
using namespace std;
CircularLinkedList::CircularLinkedList() {
	head = NULL;
	current = NULL;
	length = 0;
	
}
CircularLinkedList::~CircularLinkedList() {
	
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
int CircularLinkedList::lengthIs() const {
		return length;
}


void CircularLinkedList::insertItem(ItemType &item) {
	current = head;
	NodeType *temp = new NodeType;
		temp->data = item;
		
	if(current == NULL) {
		temp->next = temp;
		head = temp;
		goto label;
		
	}
	if(item.getValue() == head->data.getValue()) { //checks special case of the beggining
		cout << "Item " << item.getValue() << " exists and was not added" << endl;
				goto label2;
	}
	current = current->next;
	while(current != head) {  //checks if item is in list besides the beggining
		if(current->data.getValue() == item.getValue()) {
			cout << "Item " << item.getValue() << " exists and was not added" << endl;
			goto label2;
		}
		current = current->next;
	}
	current = head;
	 if(current->data.getValue() >= temp->data.getValue()) {
		while(current->next != head) {
			current = current->next;
		}
		current->next = temp;
		temp->next = head;
		head = temp;
	}
	else {
		while(current->next != head && current->next->data.getValue() < temp->data.getValue()) {
			current = current->next;
		}
		temp->next = current->next;
		current->next = temp;
	
	}
	label:
	length++;
	label2:
	int j;
}
	
void CircularLinkedList::deleteItem(ItemType &item) {
	NodeType *temp;
	current = head;
	if(isEmpty()){
	cout << "List is empty" << endl;
			head = NULL;
			current = NULL;
	}
	

	else {
	
	while(current->data.getValue() != item.getValue()) { //checks if item is in list
		
		if(current->next == head) {
			cout << "Item not in list!" << endl;
			goto label;
		}
		temp = current; //temp is equal to previous node
		current = current->next; //incremenet current
	}
	
	if(current == head) {
		temp = head;
		while(temp->next != head) {
			temp = temp->next;
		}
		head = current->next;
		temp->next = head;
		
	}
	else if(current->next == head) {
		temp->next = head;
		
	}	
	else {
	temp->next = current->next;
	
	
	}
	
}
length--;
label:
int i;
}

bool CircularLinkedList::isEmpty() { //call whenever want to check if Head is null
	if(this->head == NULL) {
		
		return true;
	}
	else {
		return false;
	}
}
void CircularLinkedList::print() {
	
NodeType* temp = head;
if(length == 0) {
	cout << "List is empty!" << endl;
}
else {
int i = 0;
  while(i < length){
       ((temp->data).print());  //just printing value of a temp NodeType equal to the head
        temp = (temp->next);
       i++;
    } 
	cout << endl;

}
}


	
