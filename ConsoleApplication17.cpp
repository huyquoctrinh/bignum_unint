#include<iostream>
#include<string>
#include<math.h>
#include<stdint.h>
#include"dynamic_core.h"
#include"math_big.h"
using namespace std;
int main() {
	bigint a, b, res;
	string a1 = "";
	string x1 = "2469129952444475555557356656564345978899799979058790779696596594646865767338";
	string b1 = "";
	a = string2bigint(a1);
	b = string2bigint(b1);
	//res = init(res, 128);
	output(a);
	res = multiply(a,b);
	output(res);
	//output(res);
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
