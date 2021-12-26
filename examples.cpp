#include <iostream>
#include "class_BIG_NUM.cpp"
using namespace std;

int main(){
	BIG_NUM* big1 = new BIG_NUM("3123121231231241");
	BIG_NUM* big2 = new BIG_NUM(3123214);
	BIG_NUM* res = new BIG_NUM();
	
	BIG_NUM::sum(res, big1, big2);
	
	res->show_number(); // 3123121231231241 + 3123214
	cout << "\n\n";
	
	BIG_NUM* big3 = new BIG_NUM("9234234123675");
	BIG_NUM* big4 = new BIG_NUM("6798236464879");
	BIG_NUM* res2 = new BIG_NUM();
	
	BIG_NUM::product(res2, big3, big4); //9234234123675 * 6798236464879
	
	res2->show_number();
	cout << "\n\n";
	
	BIG_NUM* big5 = new BIG_NUM(4096);
	BIG_NUM* res3 = new BIG_NUM();
	
	BIG_NUM::pow(res3, big5, 25); //4096 ^ 25
	res3->show_number();
	
	
	return 0;
}

