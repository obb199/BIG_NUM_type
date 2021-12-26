#include <iostream>
#include "class_Node.cpp"

using namespace std;

class DoublyLinkedList{
	//A doublyLinkedList is a LinkedList with nodes doubly referenceds. This class only has the pointer to the first and last node, with this the DLL has some methods to manipulate the nodes.
	
	private:
		Node* head;
		Node* tail;
	
	public:
		//Construtor:
		DoublyLinkedList(){
			this->head = NULL;
			this->tail = NULL;
		}
		
		//Setters and Getters methods:
		
		void set_head(Node* head){
			this->head = head;
		}
		
		Node* get_head(){
			return head;
		}
		
		void set_tail(Node* tail){
			this->tail = tail;
		}
		
		Node* get_tail(){
			return tail;
		}
		
		//Method to put a new node at the beginning of list
		void add_new_digit(unsigned long long digits, int zeros){ // add_new_head // set new_head // set_head
			Node* new_digit = new Node(digits, zeros);
			
			if(head == NULL){
				this->head = new_digit;
			}else if(tail == NULL){
				head->set_previous(new_digit);
				new_digit->set_next(head);
				tail = head;
				head = new_digit;
			}else{
				head->set_previous(new_digit);
				new_digit->set_next(head);
				head = new_digit;
			}
	}
		
		//Method to put a new node at the end of list.
		void add_of_product(unsigned long long digits, int zeros){ // add_new_tail // set new_tail // set_tail
			Node* new_node = new Node(digits, zeros);
			
			if (head == NULL){
				head = new_node;
			}else if (tail == NULL){
				head->set_next(new_node);
				new_node->set_previous(head);
				tail = new_node;
			}else{
				tail->set_next(new_node);
				new_node->set_previous(tail);
				tail = new_node;
			}
		}
		
		//Method to show the numbers of the list.
		void show_digits(){
			Node* new_digit = head;
						
			if (head->get_digits() == 0){
				Node* new_digit = head->get_next();
			}
			
			while(new_digit != NULL){
				if (new_digit != this->head){
					for(int i = 0; i < new_digit->get_initial_zeros(); i++){
						cout << 0;
					}
				}
				cout << new_digit->get_digits();
				new_digit = new_digit->get_next();
			}
			delete new_digit;
		}		
};
