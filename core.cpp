#include<iostream>
#include<stdint.h>
#include"dynamic_core.h"
#include<string>
using namespace std;
int getLength(string a) {
	return a.size();
}
int getlByte(bigint a) {
	return a.data.length;
}
bigint init(bigint &a, int l) {
	a.data.length = l;
	a.data.byte = (uint16_t*)calloc(l, sizeof(uint16_t));;
	return a;
}
void output(bigint a) {
	if (a.dau == 0) {
		cout << "-";
	}
	for (int i = 0; i < a.data.length; i++) {
		cout << a.data.byte[i];
	}

}
void out_string(string a) {
	for (int i = 0; i < a.size(); i++) {
		cout << a[i];
	}
}
void delete_fron(bigint& a,int count) {
	for (int i = 0; i < count; i++) {
		pop_front(a);
	}
}
bigint string2bigint(string s) {
	bigint res;
	unsigned int count=0;
	if (s[0] == '-') {
		int l = s.length() - 1;
	}
	
	long long l = s.length();
	init(res, l);
	cout << l<<"\n";
	//cout << res.data.length<<"\n";
	if (s[0] == '-') {
		res.dau = 0;
		for (int i = 1; i < l; i++) {
			push_back(res,int(s[i] - 48));
			pop_front(res);
			count++;
		}
		count += 1;
	}
	else if ((s[0] != '-') || (s[0] == '+')) {
		res.dau = 1;
		for (int i = 0; i < l; i++) {
			res.data.byte[i] == s[i];
			push_back(res,int(s[i] - 48));
			pop_front(res);
			count++;
		}
	}
	//delete_fron(res, count);
	return res;
}
string bigint2string(bigint a) {
	string res;
	for (int i = 0; i < a.data.length; i++) {
		res = res + to_string(a.data.byte[i]);
	}
	return res;
}
void push_back(bigint& a, int n) {
	a.data.length += 1;
	a.data.byte[a.data.length - 1] = n;
}
void push_front(bigint& a, int n) {
	a.data.length += 1;
	for (int i = a.data.length; i >= 0; i--) {
		a.data.byte[i + 1] = a.data.byte[i];
	}
	a.data.byte[0] = n;
}
void pop_back(bigint& a) {
	a.data.length -= 1;
}
void pop_front(bigint& a) {
	for (int i = 0; i < a.data.length - 1; i++) {
		a.data.byte[i] = a.data.byte[i + 1];
	}
	a.data.length--;
}
int getDigit(bigint a, int pos) {
	int l = getlByte(a);
	if (pos < l) {
		return a.data.byte[pos];
	}
	else {
		return -1;
	}
}
void delete_trash(bigint& a, int count) {
	for (int i = 0;i<count; i++) {
		pop_back(a);
	}
}
bigint reverse(bigint& a) {
	int l = getlByte(a);
	bigint res;
	res = init(res, l);
	for (int i = 0; i < l; i++) {
		res.data.byte[i] = a.data.byte[l-i-1];
	}
	return res;
}