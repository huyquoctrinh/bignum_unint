#include<iostream>
#include<string>
#include<math.h>
#include<stdint.h>
#include"dynamic_core.h"
#include"math_big.h"
using namespace std;
int main() {
	bigint a, b, res;
	string a1 = "-200";
	string b1 = "223";
	a = string2bigint(a1);
	b = string2bigint(b1);
	//push_front(b, 0);
	//push_front(b, 0);
	//output(res);
	//cout << compare(a, b);
	res = substract(a,b);
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
	cout << res.dau;
}
