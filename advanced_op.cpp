#include<iostream>
#include<string>
#include<math.h>
#include<stdint.h>
#include<sstream>
#include"dynamic_core.h"
#include"math_big.h"
#include "adv.h"
using namespace std;
void abs(bigint& a) {
	a.dau = 1;
}
bigint min(bigint* a,int n) {
	bigint min;
	for (int i = 0; i < n-1; i++) {
		for (int j = i; j < n; j++) {
			if (compare_full(a[j], a[i]) <=0) {
				min = a[j];
			}
		}
	}
	return min;
}
bigint max(bigint* a, int n) {
	bigint max;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i; j < n; j++) {
			if (compare_full(a[j], a[i]) >=0) {
				max= a[j];
			}
		}
	}
	return max;

}
bigint pow(bigint a,int n) {
	if (n == 0) {
		bigint res;
		init(res, 1);
		res.data.byte[0] = 1;
		return res;
	}
	else if (n == 1) {
		return a;
	}
	else if (n == 0) {
		bigint res;
		init(res, 1);
		res.data.byte[0] = 0;
		return res;
	}
	return multiply(a,pow(a, n - 1));
}

string to_base32(bigint a) {
	bigint zero;
	string res;
	init(zero, 1);
	zero.data.byte[0] = 0;
	while (compare_full(a, zero) == 1) {
		int d = mod(a,32);
		if (d < 10)
		{
			res.insert(0, 1, '0' + d);
		}
		else
		{
			res.insert(0, 1, 'a' + d - 10);
		}
		a = divide(a,32);
	}
	return res;
}
char valuetochar64(int v)
{
	char c;
	switch (v)
	{
	case 0: c = 'A'; break; case 1: c = 'B'; break; case 2: c = 'C'; break; case 3: c = 'D'; break;
	case 4: c = 'E'; break; case 5: c = 'F'; break; case 6: c = 'G'; break; case 7: c = 'H'; break;
	case 8: c = 'I'; break; case 9: c = 'J'; break; case 10: c = 'K'; break; case 11: c = 'L'; break;
	case 12: c = 'M'; break; case 13: c = 'N'; break; case 14: c = 'O'; break; case 15: c = 'P'; break;
	case 16: c = 'Q'; break; case 17: c = 'R'; break; case 18: c = 'S'; break; case 19: c = 'T'; break;
	case 20: c = 'U'; break; case 21: c = 'V'; break; case 22: c = 'W'; break; case 23: c = 'X'; break;
	case 24: c = 'Y'; break; case 25: c = 'Z'; break; case 26: c = 'a'; break; case 27: c = 'b'; break;
	case 28: c = 'c'; break; case 29: c = 'd'; break; case 30: c = 'e'; break; case 31: c = 'f'; break;
	case 32: c = 'g'; break; case 33: c = 'h'; break; case 34: c = 'i'; break; case 35: c = 'j'; break;
	case 36: c = 'k'; break; case 37: c = 'l'; break; case 38: c = 'm'; break; case 39: c = 'n'; break;
	case 40: c = 'o'; break; case 41: c = 'p'; break; case 42: c = 'q'; break; case 43: c = 'r'; break;
	case 44: c = 's'; break; case 45: c = 't'; break; case 46: c = 'u'; break; case 47: c = 'v'; break;
	case 48: c = 'w'; break; case 49: c = 'x'; break; case 50: c = 'y'; break; case 51: c = 'z'; break;
	case 52: c = '0'; break; case 53: c = '1'; break; case 54: c = '2'; break; case 55: c = '3'; break;
	case 56: c = '4'; break; case 57: c = '5'; break; case 58: c = '6'; break; case 59: c = '7'; break;
	case 60: c = '8'; break; case 61: c = '9'; break; case 62: c = '+'; break; case 63: c = '/'; break;
	}
	return c;
}
char valuetochar58(int v) {
	char c;
	switch (v)
	{
	case 0: c = '1'; break; case 1: c = '2'; break; case 2: c = '3'; break; case 3: c = '4'; break;
	case 4: c = '5'; break; case 5: c = '6'; break; case 6: c = '7'; break; case 7: c = '8'; break;
	case 8: c = '9'; break; case 9: c = 'A'; break; case 10: c = 'B'; break; case 11: c = 'C'; break;
	case 12: c = 'D'; break; case 13: c = 'E'; break; case 14: c = 'F'; break; case 15: c = 'G'; break;
	case 16: c = 'H'; break; case 17: c = 'J'; break; case 18: c = 'K'; break; case 19: c = 'L'; break;
	case 20: c = 'M'; break; case 21: c = 'N'; break; case 22: c = 'P'; break; case 23: c = 'Q'; break;
	case 24: c = 'R'; break; case 25: c = 'S'; break; case 26: c = 'T'; break; case 27: c = 'U'; break;
	case 28: c = 'V'; break; case 29: c = 'W'; break; case 30: c = 'X'; break; case 31: c = 'Y'; break;
	case 32: c = 'Z'; break; case 33: c = 'a'; break; case 34: c = 'b'; break; case 35: c = 'c'; break;
	case 36: c = 'd'; break; case 37: c = 'e'; break; case 38: c = 'f'; break; case 39: c = 'g'; break;
	case 40: c = 'h'; break; case 41: c = 'i'; break; case 42: c = 'j'; break; case 43: c = 'k'; break;
	case 44: c = 'm'; break; case 45: c = 'n'; break; case 46: c = 'o'; break; case 47: c = 'p'; break;
	case 48: c = 'q'; break; case 49: c = 'r'; break; case 50: c = 's'; break; case 51: c = 't'; break;
	case 52: c = 'u'; break; case 53: c = 'v'; break; case 54: c = 'w'; break; case 55: c = 'x'; break;
	case 56: c = 'y'; break; case 57: c = 'z'; break;}
	return c;
}
string to_base64(bigint a) {
	bigint zero;
	string res;
	init(zero, 1);
	zero.data.byte[0] = 0;
	while (compare_full(a, zero) == 1) {
		int d = mod(a, 64);
		res.push_back(valuetochar64(d));
		a = divide(a, 64);
	}
	return res;
}
string to_base58(bigint a) {
	bigint zero;
	string res;
	init(zero, 1);
	zero.data.byte[0] = 0;
	while (compare_full(a, zero) == 1) {
		int d = mod(a, 58);
		res.push_back(valuetochar58(d));
		a = divide(a, 58);
	}
	return res;
}
