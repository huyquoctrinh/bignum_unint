#include<iostream>
#include<string>
#include<math.h>
#include<stdint.h>
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