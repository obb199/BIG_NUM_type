#include <iostream>
#include "class_BIG_NUM.cpp"
using namespace std;

int main(){
	BIG_NUM* big1 = new BIG_NUM("3123121231231241");
	BIG_NUM* big2 = new BIG_NUM(3123214);
	BIG_NUM* res = new BIG_NUM();
	
	BIG_NUM::sum(res, big1, big2);
	
	res->show_number(); // 3123121231231241 + 3123214 = 3123121234354455
	cout << "\n\n";
	
	BIG_NUM* big3 = new BIG_NUM("9234234123675");
	BIG_NUM* big4 = new BIG_NUM("6798236464879");
	BIG_NUM* res2 = new BIG_NUM();
	
	BIG_NUM::product(res2, big3, big4); 
	
	res2->show_number(); //9234234123675 * 6798236464879 = 62776507144797362479910325
	cout << "\n\n";
	
	BIG_NUM* big5 = new BIG_NUM(4096);
	BIG_NUM* res3 = new BIG_NUM();
	
	BIG_NUM::pow(res3, big5, 50); 
	res3->show_number(); //4096 ^ 50 = 
	//4149515568880992958512407863691161151012446232242436899995657329690652811412908146399707048947103794288197886611300789182395151075411775307886874834113963687061181803401509523685376
	cout << "\n\n";
	
	BIG_NUM* n5 = new BIG_NUM("9523452343076575675");
	BIG_NUM* n6 = new BIG_NUM("102326597787658575");
	BIG_NUM* res4 = new BIG_NUM();

 	BIG_NUM::division(res4, n5, n6);
 	res4->show_number(); //(int)9523452343076575675/102326597787658575 = 93
 	cout << "\n\n";
	
	return 0;
}

