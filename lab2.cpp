#include<iostream>
using namespace std;

//A class node that has adata and a pointer and a default constructor that makes the pointer point to NULL
class Node{
	public:
	//Data
	int data;
	//Pointer to the next Node
	Node * next;
	//Constructor that makes the pointer NULL
	Node(){
		next = NULL;
		}
};

//A class LinkedList that linkes all the nodes and performs operations like insert, delete, insertAt, deleteAt
class LinkedList{
	//Head and circles inside linked with one another
	public:
	//Head and tail --> circle(Node) type pointer
	Node * head;
	Node * tail;
	//constructor
	LinkedList(){
		head = NULL;
		tail = NULL;
	}

	//Insert
	void insert(int value){
		//If 1st node is added
		Node * temp = new Node;
		//inserting data in the new node object created in the heap
		temp->data = value;
		//1st node only
		if(head == NULL){
			head = temp;
			}
		//Any other Node only
		else{
			tail->next = temp;	
			}
		tail = temp;	
	}

	//Insertion at a specific position
	void insertAt(int pos, int value){
		//Reach the place before the position
		Node * current = head;
		int i=1;
		while(i<pos-1){
			i++;
			current = current->next;
		}
		//create a Node
		Node * temp = new Node;
		temp->data = value;

		//Moving pointers like magic !
		temp->next = current->next;
		current->next = temp;
	}	

	//Deletion of the last element
	void delet(){
		//store the tail in temp
		Node * temp = tail;
		//the one before tail has to point to null
		Node * current = head;
		while(current->next != tail){
			current = current->next;
		}
		current->next = NULL;
		//update tail
		tail = current;
		//delete temp
		delete temp;
	}

	//Deletion at a specific position
	void deleteAt(int pos){
		//Current node points to head
      		Node * current = head;
        	int i =1;
        	while(i < pos-1){
            		i++;
            		current = current->next;
        	}
		Node * temp = tail;
     		current->next = NULL;
		// update tail
        	tail = current;
        	// delete temp
         	delete temp;
	}

	//Display
	void display(){
		Node * current = head;
		while(current != NULL){
			cout<< current->data << "->";
			current = current->next;
		
		}
	cout << endl;
	}
};

//Main function
int main(){
    	LinkedList l1;
    	l1.insert(1);
    	l1.insert(2);
    	l1.insert(3);
    	l1.display();
    	l1.insertAt(1, 4);
    	l1.display();
    	l1.delet();
    	l1.display();
    	l1.deleteAt(2);
    	l1.display();
    
    return 1;
}
