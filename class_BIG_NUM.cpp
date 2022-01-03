#include <iostream>
#include <string>
#include <cstddef>
#include "class_DoublyLinkedList.cpp"


class BIG_NUM{
	//BIG_NUM is represented by a DoublylinkedList and a set of methods to manipulate the numbers. You can create a big num with other int or use a string.
	private:
		DoublyLinkedList* big_num;
		bool negative;
		//FOR OTHER TIME (DIVISION, MOD, AND OTHERS TOO)
	
	public:
		//Constructor with no parameters, create a big num with zero value
		BIG_NUM(){
			big_num = new DoublyLinkedList();
			Node* node = new Node(0, 0);
			big_num->set_head(node);
			set_negative(false);
		}
		
		//Construtor to create a big num using a string like "87129312738921"
		BIG_NUM(string string_number){
			big_num = new DoublyLinkedList();
			
			if (string_number[0] == '-'){
				set_negative(true);
			}else{
				set_negative(false);
			}
			
			char aux;
			for(int i = 0; i < string_number.length()/2; i++){
				aux = string_number[i];
				string_number[i] = string_number[string_number.length() - i - 1];
				string_number[string_number.length() - i - 1] = aux;
			}
			
			int i = 0;
			int mult_num = 1;
			long long num = 0;
			int zeros = 0;
			
			while (string_number[i] != '\0'){
				if (string_number[i] == '-'){
					i++;
					continue;
				}	
				
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
			
			if (num > 0){
				big_num->add_new_digit(num, zeros);
			}
		}	
		
		//Construtor to create a big num using a long long number
		BIG_NUM(long long number){
			
			big_num = new DoublyLinkedList();
			big_num->add_new_digit(abs(number), count_of_zeros(number));
			
			if (number > 0){
				set_negative(false);
			}else{
				set_negative(true);
			}
		}
		
		//Setters and Getters:
		DoublyLinkedList* get_DoublylinkedList(){
			return this->big_num;
		}
		
		void set_DoublyLinkedList(DoublyLinkedList* l){
			big_num = l;
		}
		
		bool get_negative(){
			return negative;
		}
		
		void set_negative(bool negative){
			this->negative = negative;
		}
		
		//Function to return the count of numbers exist in the number
		int length(){
			int length = 0;
			
			Node* node_aux = big_num->get_head();
			
			length += 9 - BIG_NUM::count_of_zeros(big_num->get_head()->get_digits());
			node_aux = node_aux->get_next();
			
			while(node_aux){
				length += 9;
				node_aux = node_aux->get_next();
			}
			
			delete node_aux;
			return length;
		}
		
		//Method to discover how much zeros are in some number, any node has maximum of 9 digits, if this number is smaller then that, he gonna has some zeros at the end.
		static int count_of_zeros(long long number){
			number = number%1000000000;
			
			int i = 0;
			while(number > 0){
				number = number/10;
				i++;
			}
			
			return 9 - i;	
		}
		
		//transforming a int in a string.
		static string int_to_string(long long n){
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
			if (negative){
				cout << '-';
			}
			big_num->show_digits();
		}
		
		static void swap(BIG_NUM* n1, BIG_NUM* n2){
			BIG_NUM* aux = new BIG_NUM();
			aux->set_DoublyLinkedList(n1->get_DoublylinkedList());
			n1->set_DoublyLinkedList(n2->get_DoublylinkedList());
			n2->set_DoublyLinkedList(aux->get_DoublylinkedList());
		}
		
		//Adding a new part of the BIG_NUM
		void add_new_digit(int digit, char zeros){
			big_num->add_new_digit(digit, zeros);
		}
		
		//Adding a new part of the number when the program is making a product
		void add_of_product(int digit, char zeros){
			big_num->add_of_product(digit, zeros);
		}
		
		//if n1 > n2 return 1, if n2 > n1 return 2, if n1 == n2 return 0. (the comparation is only for module of number, because that, the signal is not verified)
		static int comparison(BIG_NUM* n1, BIG_NUM*n2){
			if(n1->length() > n2->length()){
				return 1;
			}else if (n2->length() > n1->length()){
				return 2;
			}else{
				Node* node1 = n1->get_DoublylinkedList()->get_head();
				Node* node2 = n2->get_DoublylinkedList()->get_head();
				
				while (node1 != NULL)
				if (node1->get_digits() > node2->get_digits()){
					return 1;
				}else if (node2->get_digits() > node1->get_digits()){
					return 2;
				}else{
					node1 = node1->get_next();
					node2 = node2->get_next();
				}
			}
			return 0;
		}
		
		//SUMS:
		
		static void sum(BIG_NUM* result, BIG_NUM* n1, BIG_NUM* n2){ // n(big_num) = n1(big_num) + n2(big_num);
			//NEEDS UPDATE!		
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
			long long digits = 0;
			int amount_of_zeros = 0;
			
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

				if (digits >= 1000000000){
					digits = digits%1000000000;
					rest = 1;
				}
				
				amount_of_zeros = BIG_NUM::count_of_zeros(digits);
				result->add_new_digit(digits, amount_of_zeros);
				digits = rest;
			}
			
			if (rest != 0){
				result->add_new_digit(rest, 8);
			}
		}
	
		static void sum(BIG_NUM* n1, BIG_NUM* n2){ // n1 = n1(big_num) + n2(big_num);
			BIG_NUM* result = new BIG_NUM();
			sum(result, n1, n2);
			
			n1->set_DoublyLinkedList(result->get_DoublylinkedList());
			delete result;
			
		}
		
		static void sum(BIG_NUM* result, BIG_NUM* n1, long long n2){ // n(big_num) = n1(big_num) + n2(long long);
			BIG_NUM* bign2 = new BIG_NUM(n2);
			BIG_NUM::sum(result, n1, bign2);
			delete bign2;
		}	
		
		static void sum(BIG_NUM* result, long long n1, long long n2){ //n(big_num) = n1(long long) + n2(long long)
			BIG_NUM* big1 = new BIG_NUM(n1);
			BIG_NUM* big2 = new BIG_NUM(n2);
			BIG_NUM::sum(result, big1, big2);
			delete big1;
			delete big2;
		}
		
		static void sum(BIG_NUM* n1, long long n2){ // n1(big_num) = n1(big_num) + long long
			BIG_NUM* big = new BIG_NUM(n2);
			BIG_NUM::sum(n1, big);
			delete big;
		}
		
		//PRODUCTS:
		static void product(BIG_NUM* n1, BIG_NUM* n2){ // n1 (big_num) = n1(big_num) * n2(big_num)
			//NEEDS UPDATE!
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
					long long prod = Node_n1->get_digits()*Node_n2->get_digits();
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
		
		static void product(BIG_NUM* result, BIG_NUM* n1, long long n2){ //n(big_num) = n1(big_num) * n2 (long long)	
			BIG_NUM* big_n2 = new BIG_NUM(n2);
			BIG_NUM::product(result, n1, big_n2);
			delete big_n2;	
		}
		
		static void product(BIG_NUM* n1, long long n2){// n1(big_num) = n1(big_num) * n2(long long		
			BIG_NUM* big_n2 = new BIG_NUM(n2);
			BIG_NUM::product(n1, big_n2);
			delete big_n2;	
		}
		
		static void pow(BIG_NUM* result, BIG_NUM* n1, long long n2){// n(big_num) = n1(big_num)^n2(long long)
			BIG_NUM* res = new BIG_NUM(1);
				
			for(int i = 0; i < n2; i++){
				BIG_NUM::product(res, n1);
			}
				
			result->set_DoublyLinkedList(res->get_DoublylinkedList());
			delete res;
		}
	
		static void pow(BIG_NUM* result, long long n1, long long n2){// n(big_num) = n1(long long)^n2(long long)
			BIG_NUM* big1 = new BIG_NUM(n1);
			BIG_NUM::pow(result, big1, n2);
		}
		
		static void pow(BIG_NUM* n1, long long n2){// n1(big_num) = n1(big_num)^n2(long long)
			BIG_NUM* result = new BIG_NUM();
			BIG_NUM::pow(result, n1, n2);
			n1->set_DoublyLinkedList(result->get_DoublylinkedList());	
		}
		
		//SUBTRACTIONS:
		static void subtraction(BIG_NUM* result, BIG_NUM* n1, BIG_NUM* n2){ // n(big_num) = n1(big_num) + n2(big_num)
			int comp = BIG_NUM::comparison(n1, n2);
			
			//Comparações iniciais
			if(comp == 0 && n1->get_negative() == n2->get_negative()){ //Working
				DoublyLinkedList* list = new DoublyLinkedList();
				Node* node = new Node(0, 9);
				list->set_head(node);
				result->set_DoublyLinkedList(list);
				result->set_negative(false);
			}else if (comp == 0 && n1->get_negative() != n2->get_negative()){ //Working
				if (n1->get_negative()){
					result->set_negative(true);
				}else{
					result->set_negative(false);
				}
				BIG_NUM::product(result, n1, 2);
			}else if ((n1->get_negative() == n2->get_negative() && n1->get_negative())){
				n1->set_negative(false);
				n2->set_negative(false);
				BIG_NUM::sum(result, n1, n2);
				result->set_negative(true);
				n1->set_negative(true);
				n2->set_negative(true);
			}else if (n1->get_negative() && !n2->get_negative()){
				n2->set_negative(false);
				BIG_NUM::sum(result, n1, n2);
				result->set_negative(true);
				n1->set_negative(false);
				n2->set_negative(true);
				
			}else{ // n1->get_negative() && n2->get_negative()
				if (comp == 2){
					result->set_negative(true);
					swap(n1, n2);
				}else{
					result->set_negative(false);
				}
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
				
				long long value_to_add = 0;
				bool passed = false;
				long long rest = 0;
				
				while(Node_n1 != NULL){
					if (passed){
						value_to_add = -1;
						passed = false;
					}else{
						value_to_add = 0;
					}
					if (Node_n2 != NULL){
						if (Node_n1->get_digits() >= Node_n2->get_digits()){
							value_to_add += Node_n1->get_digits() - Node_n2->get_digits();
							Node_n1 = Node_n1->get_previous();
							Node_n2 = Node_n2->get_previous();
						}else{	
							value_to_add += 1000000000+Node_n1->get_digits() - Node_n2->get_digits();
							passed = true;
							Node_n1 = Node_n1->get_previous();
							Node_n2 = Node_n2->get_previous();
						}
					}else{
						value_to_add += Node_n1->get_digits();
						Node_n1 = Node_n1->get_previous();
					}
					result->add_new_digit(value_to_add, count_of_zeros(value_to_add));
				}
				if (comp == 2){
					swap(n1, n2);
				}
			}	
		}
		
		static void subtraction(BIG_NUM* n1, BIG_NUM* n2){ // n1(big_num) = n1(big_num) + n2(big_num)
			BIG_NUM* result = new BIG_NUM();
			result->set_DoublyLinkedList(n1->get_DoublylinkedList());
			BIG_NUM::subtraction(result, n1, n2);
			n1->set_DoublyLinkedList(result->get_DoublylinkedList());
			delete result;
		}
		
		static void subtraction(BIG_NUM* n1, long long n2){ //n1(big_num) = n1(big_num) + n2(long long)
			BIG_NUM* big_n2 = new BIG_NUM(n2);
			BIG_NUM::subtraction(n1, big_n2);
		}
		
		static void subtraction(BIG_NUM* result, BIG_NUM* n1, long long n2){ //n(big_num) = n1(big_num) + n2(long long)
			BIG_NUM* big_n2 = new BIG_NUM(n2);
			BIG_NUM::subtraction(result, n1, big_n2);
		}	
		
		static void subtraction(BIG_NUM* result, long long n1, long long n2){ //n(big_num) = n1(long long) + n2(long long)
			BIG_NUM* big_n1 = new BIG_NUM(n1);
			BIG_NUM* big_n2 = new BIG_NUM(n2);
			
			BIG_NUM::subtraction(result, big_n1, big_n2);
		}				
};
