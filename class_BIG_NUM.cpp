#include <iostream>
#include <string>
#include <cstddef>
#include "class_DoublyLinkedList.cpp"

class BIG_NUM{
	//BIG_NUM is represented by a DoublylinkedList and a set of methods to manipulate the numbers. You can create a big num with other int or use a string.
	private:
		DoublyLinkedList* big_num;
		//bool negative; # FOR OTHER TIME... (SUBTRATION, DIVISION AND MOD TOO..)
	
	public:
		//Constructor with no parameters, create a big num with zero value
		BIG_NUM(){
			big_num = new DoublyLinkedList();
			Node* node = new Node(0, 0);
			big_num->set_head(node);
		}
		
		//Construtor to create a big num using a string like "87129312738921"
		BIG_NUM(string string_number){
			big_num = new DoublyLinkedList();
			
			char aux;
			for(int i = 0; i < string_number.length()/2; i++){
				aux = string_number[i];
				string_number[i] = string_number[string_number.length() - i - 1];
				string_number[string_number.length() - i - 1] = aux;	
			}
			
			int i = 0;
			int mult_num = 1;
			unsigned long long num = 0;
			int zeros = 0;
			
			while (string_number[i] != '\0'){	
				if ((int)string_number[i] - 48 == 0){
					zeros++;
					mult_num *= 10;
				}else{
					zeros = 0;
					num += ((int)string_number[i] - 48)*mult_num;
					mult_num *= 10;
				}			
				i++;
			
				if (mult_num > 100000000){
					big_num->add_new_digit(num, zeros);
					mult_num = 1;
					zeros = 0;
					num = 0;
				}
			}
			
			if (mult_num > 0){
				big_num->add_new_digit(num, zeros);
			}
		}		
		
		//Construtor to create a big num using a unsigned long long number
		BIG_NUM(unsigned long long number){
			big_num = new DoublyLinkedList();
			big_num->add_new_digit(number, 0);
		}
		
		//Setters and Getters:
		DoublyLinkedList* get_DoublylinkedList(){
			return this->big_num;
		}
		
		void set_DoublyLinkedList(DoublyLinkedList* l){
			big_num = l;
		}
		
		//Method to discover how much zeros are in some number, any node has maximum of 9 digits, if this number is smaller then that, he gonna has some zeros at the end.
		static int count_of_zeros(unsigned long long number){
			number = number%1000000000;
			
			int i = 0;
			while(number > 0){
				number = number/10;
				i++;
			}
			
			return 9 - i;	
		}
		
		//transforming a int in a string.
		static string int_to_string(unsigned long long n){
		    string v = "";
			while (n > 0){
				int d = n%10;
				n = n/10;
				
				switch (d){
					case 0:
						v = '0' + v;
						break;
					case 1:
						v = '1' + v;
						break;
					case 2:
						v = '2' + v;
						break;
					case 3:
						v = '3' + v;
						break;
					case 4:
						v = '4' + v;
						break;
					case 5:
						v = '5' + v;
						break;
					case 6:
						v = '6' + v;
						break;
					case 7:
						v = '7' + v;
						break;
					case 8:
						v = '8' + v;
						break;
					case 9:
						v = '9' + v;
						break;
				}
			}
			return v;
		}
		
		//Method to visualize the number
		void show_number(){
			big_num->show_digits();
		}
		
		//Adding a new part of the BIG_NUM
		void add_new_digit(int digit, char zeros){
			big_num->add_new_digit(digit, zeros);
		}
		
		//Adding a new part of the number when the program is making a product
		void add_of_product(int digit, char zeros){
			big_num->add_of_product(digit, zeros);
		}
		
		//SUMS:
		
		static void sum(BIG_NUM* result, BIG_NUM* n1, BIG_NUM* n2){ // n(big_num) = n1(big_num) + n2(big_num);			
			DoublyLinkedList * null_list = new DoublyLinkedList();
			result->set_DoublyLinkedList(null_list);
			Node* Node_n1 = n1->get_DoublylinkedList()->get_head();
			Node* Node_n2 = n2->get_DoublylinkedList()->get_head();
			
			if (n1->get_DoublylinkedList()->get_tail() != NULL){
				Node_n1 = n1->get_DoublylinkedList()->get_tail();
			}
			
			if (n2->get_DoublylinkedList()->get_tail() != NULL){
				Node_n2 = n2->get_DoublylinkedList()->get_tail();
			}		
			
			int rest = 0;
			unsigned long long digits = 0;
			int count_of_zeros = 0;
			
			while(Node_n1 != NULL || Node_n2 != NULL){
				if (rest == 1){
					digits = 1;
					rest = 0;
				}
				
				if (Node_n1 != NULL){
					digits += Node_n1->get_digits();
					Node_n1 = Node_n1->get_previous();
				}
				if (Node_n2 != NULL){
					digits += Node_n2->get_digits();
					Node_n2 = Node_n2->get_previous();
				}	
				
				int count_of_zeros = BIG_NUM::count_of_zeros(digits);

				if (digits >= 1000000000){
					digits = digits%1000000000;
					rest = 1;
				}
				result->add_new_digit(digits, count_of_zeros);
				digits = rest;
			}
			
			if (rest != 0){
				result->add_new_digit(rest, 8);
			}
		}
	
		static void sum(BIG_NUM* n1, BIG_NUM* n2){ // n1 = n1(big_num) + n2(big_num);
			BIG_NUM* result = new BIG_NUM();	
			DoublyLinkedList * null_list = new DoublyLinkedList();
			result->set_DoublyLinkedList(null_list);
			Node* Node_n1 = n1->get_DoublylinkedList()->get_head();
			Node* Node_n2 = n2->get_DoublylinkedList()->get_head();
				
			if (n1->get_DoublylinkedList()->get_tail() != NULL){
				Node_n1 = n1->get_DoublylinkedList()->get_tail();
			}
				
			if (n2->get_DoublylinkedList()->get_tail() != NULL){
				Node_n2 = n2->get_DoublylinkedList()->get_tail();
			}		
				
			int rest = 0;
			unsigned long long digits = 0;
			int count_of_zeros = 0;
				
			while(Node_n1 != NULL || Node_n2 != NULL){
				if (rest == 1){
					digits = 1;
					rest = 0;
				}
					
				if (Node_n1 != NULL){
					digits += Node_n1->get_digits();
					Node_n1 = Node_n1->get_previous();
				}
				if (Node_n2 != NULL){
					digits += Node_n2->get_digits();
					Node_n2 = Node_n2->get_previous();
				}	
					
				int count_of_zeros = BIG_NUM::count_of_zeros(digits);
	
				if (digits >= 1000000000){
					digits = digits%1000000000;
					rest = 1;
				}
				result->add_new_digit(digits, count_of_zeros);
				digits = rest;
			}
				
			if (rest != 0){
				result->add_new_digit(rest, 8);
			}
			n1->set_DoublyLinkedList(result->get_DoublylinkedList());
			delete result;
		}
		
		static void sum(BIG_NUM* result, BIG_NUM* n1, unsigned long long n2){ // n(big_num) = n1(big_num) + n2(unsigned long long);
			BIG_NUM* bign2 = new BIG_NUM(n2);
			BIG_NUM::sum(result, n1, bign2);
			delete bign2;
		}	
		
		static void sum(BIG_NUM* result, unsigned long long n1, unsigned long long n2){ //n(big_num) = n1(unsigned long long) + n2(unsigned long long)
			BIG_NUM* big1 = new BIG_NUM(n1);
			BIG_NUM* big2 = new BIG_NUM(n2);
			BIG_NUM::sum(result, big1, big2);
			delete big1;
			delete big2;
		}
		
		static void sum(BIG_NUM* n1, unsigned long long n2){ // n1(big_num) = n1(big_num) + unsigned long long
			BIG_NUM* big = new BIG_NUM(n2);
			BIG_NUM::sum(n1, big);
			delete big;
		}
		
		//PRODUCTS:
		static void product(BIG_NUM* n1, BIG_NUM* n2){ // n1 (big_num) = n1(big_num) * n2(big_num)
			BIG_NUM* result = new BIG_NUM();		
			DoublyLinkedList * null_list = new DoublyLinkedList();
			result->set_DoublyLinkedList(null_list);
			Node* Node_n1 = n1->get_DoublylinkedList()->get_head();
				
			if (n1->get_DoublylinkedList()->get_tail() != NULL){
				Node_n1 = n1->get_DoublylinkedList()->get_tail();
			}
					
			int zeros;
			int zeros_n1 = 0;
			int zeros_n2 = 0;
			
			while(Node_n1 != NULL){
				zeros_n2 = 0;
				
				Node* Node_n2 = n2->get_DoublylinkedList()->get_head();
				if (n2->get_DoublylinkedList()->get_tail() != NULL){
					Node_n2 = n2->get_DoublylinkedList()->get_tail();
				}
				
				while(Node_n2 != NULL){
					unsigned long long prod = Node_n1->get_digits()*Node_n2->get_digits();
					string prod_s = BIG_NUM::int_to_string(prod);
				
					for(int i = 0; i < zeros_n1 + zeros_n2; i++){
						prod_s += "000000000";
					}
					
					BIG_NUM* big_num_sum = new BIG_NUM(prod_s);
					BIG_NUM::sum(result, big_num_sum);
					zeros_n2++;
					Node_n2 = Node_n2->get_previous();
				}	
				zeros_n1++;
				Node_n1 = Node_n1->get_previous();
			}	
			n1->set_DoublyLinkedList(result->get_DoublylinkedList());
			delete result;
		}
		
		static void product(BIG_NUM* result, BIG_NUM* n1, BIG_NUM* n2){ //n(big_num) = n1(big_num) * n2 (big_num)
			BIG_NUM* aux = new BIG_NUM();
			aux->set_DoublyLinkedList(n1->get_DoublylinkedList());
			BIG_NUM::product(n1, n2);
			result->set_DoublyLinkedList(n1->get_DoublylinkedList());
			n1->set_DoublyLinkedList(aux->get_DoublylinkedList());
			delete aux;
		}
		
		static void product(BIG_NUM* result, BIG_NUM* n1, unsigned long long n2){ //n(big_num) = n1(big_num) * n2 (unsigned long long)	
			BIG_NUM* big_n2 = new BIG_NUM(n2);
			BIG_NUM::product(result, n1, big_n2);
			delete big_n2;	
		}
		
		static void product(BIG_NUM* n1, unsigned long long n2){// n1(big_num) = n1(big_num) * n2(unsigned long long		
			BIG_NUM* big_n2 = new BIG_NUM(n2);
			BIG_NUM::product(n1, big_n2);
			delete big_n2;	
		}
		
		static void pow(BIG_NUM* result, BIG_NUM* n1, unsigned long long n2){// n(big_num) = n1(big_num)^n2(unsigned long long)
			BIG_NUM* res = new BIG_NUM(1);
				
			for(int i = 0; i < n2; i++){
				BIG_NUM::product(res, n1);
			}
				
			result->set_DoublyLinkedList(res->get_DoublylinkedList());
			delete res;
		}
	
		static void pow(BIG_NUM* result, unsigned long long n1, unsigned long long n2){// n(big_num) = n1(unsigned long long)^n2(unsigned long long)
			BIG_NUM* big1 = new BIG_NUM(n1);
			BIG_NUM::pow(result, big1, n2);
		}
		
		static void pow(BIG_NUM* n1, unsigned long long n2){// n1(big_num) = n1(big_num)^n2(unsigned long long)
			BIG_NUM* result = new BIG_NUM();
			BIG_NUM::pow(result, n1, n2);
			n1->set_DoublyLinkedList(result->get_DoublylinkedList());	
		}		
};
