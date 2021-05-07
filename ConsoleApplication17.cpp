#include<iostream>
#include<string>
#include<math.h>
#include<stdint.h>
#include"dynamic_core.h"
#include"math_big.h"
using namespace std;
int main() {
	bigint a, b, res;
	string a1 = "879327831638311731956545453654654365454233423234143413265674676554754476644556657878678686786";
	string b1 = "12312112312321312387658787348204700423984923008493292840";
	a = string2bigint(a1);
	b = string2bigint(b1);
	output(multiply(a,b));
	//push_front(b, 0);
	//push_front(b, 0);
	//output(res);
	//cout << compare(a, b);
	//res = multiply(a,b);
	//cout<< bitshift_right;
	
	/*
	makeEqualLength(b, a);
	output(a);
	cout << "...";
	output(b);
	cout << "\n"<<b.data.length;
	cout << "\n ------- \n";
	*/
	//output(add_dec(a, b));
	//delete_trash(a, 3);
	//cout << a.dau << " " << b.dau << "\n";
	//cout << res.dau<<" ";
	//cout << reverse(a);
	//output(res);
}
