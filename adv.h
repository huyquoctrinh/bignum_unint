#include<iostream>
#include "dynamic_core.h"
#include "math_big.h"
#include<stdint.h>
using namespace std;
void abs(bigint & a);
bigint min(bigint* a, int n);
bigint max(bigint* a, int n);
bigint pow(bigint a, int n);
string to_base32(bigint a);
string to_base64(bigint a);
string to_base64(bigint a);
string to_base58(bigint a);
bigint pow_prime(bigint a,int b, bigint m);
bool isPrime(bigint n, int k);
bool miller_test(int d,bigint n);
#pragma once
