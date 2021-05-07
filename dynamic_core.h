#include<iostream>
#include<stdint.h>
using namespace std;
struct pdata {
	int length = 128;
	uint16_t* byte = (uint16_t*)calloc(length,sizeof(uint16_t));
};
struct bigint {
	bool dau;
	pdata data;
	//int* data;
};
int getLength(string a);
int getlByte(bigint a);
bigint init(bigint &a, int l);
void output(bigint a);
void out_string(string a);
bigint string2bigint(string a);
string bigint2string(bigint a);
void push_back(bigint& a, int n);
void push_front(bigint& a, int n);
void pop_back(bigint& a);
void pop_front(bigint& a);
int getDigit(bigint a, int pos);
void delete_trash(bigint& a, int count);
bigint reverse(bigint a);


#pragma once
