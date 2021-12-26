#include <cstddef>

class Node{
	/*
	Basic class to represent a piece of a big number, any big number has a group of nodes with numbers until 9 digits. Nodes with less then 9 digits has some zeros, linke "000033" to 33. 
	Moreover, any node has too a reference for the previous node and for the next node, this references can be null if they don't exist.
	*/
	private:
		Node* previous;
		Node* next;
		unsigned long long digits;
		int initial_zeros = 0;
	
	public:
		// Construtor to create a new Node with some digits and amount of zeros.
		Node(unsigned long long digits, int zeros){
			this->previous = NULL;
			this->next = NULL;
			this->digits = digits;
			this->initial_zeros = zeros;
		}
		
		//Setters and getters methods:
		void set_previous(Node* previous){
			this->previous = previous;
		}
		
		Node* get_previous(){
			return previous;
		}
		
		void set_next(Node* next){
			this->next = next;
		}
		
		Node* get_next(){
			return next;
		}
		
		void set_digits(unsigned long long digits){
			this->digits = digits;
		}
		
		unsigned long long get_digits(){
			return this->digits;
		}
		
		void set_initial_zeros(int zeros){
			initial_zeros = zeros;
		}
		
		int get_initial_zeros(){
			return initial_zeros;
		}
};
