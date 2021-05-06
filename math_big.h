#include<iostream>
#include<stdint.h>
#include"dynamic_core.h"
using namespace std;
int compare(bigint a, bigint b);
bool check_dau(bigint a, bigint b);
void make_equal(bigint& a, bigint& b);
int makeEqualLength(bigint& a, bigint& b);
bigint add_bin(bigint a, bigint b);
bigint add_dec_step(bigint a, bigint b);
bigint add_dec(bigint a, bigint b);
bigint subtract_step(bigint a, bigint b);
bigint substract(bigint a, bigint b);
void equal(bigint& a, bigint& b);
int compare_full(bigint a, bigint b);
bigint subtract_step(bigint a, bigint b);
#pragma once
