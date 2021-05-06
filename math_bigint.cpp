#include<iostream>
#include<string>
#include<stdint.h>
#include"dynamic_core.h"
#include"math_big.h"
using namespace std;
int compare(bigint a, bigint b) {
    int l1 = getlByte(a);
    int l2 = getlByte(b);
    if (l1 > l2) {
        return 1;
    }
    else if (l1 < l2) {
        return -1;
    }
    else if (l1 == l2) {
        for (int i = 0; i < l1; i++) {
            if (a.data.byte[i] > b.data.byte[i]) {
                return 1;
            }
            else if (a.data.byte[i] < b.data.byte[i]) {
                return -1;
            }
        }
        return 0;
    }

}

bool check_dau(bigint a, bigint b) {
    if ((a.dau == 0) && (b.dau == 0)) {
        return true;
    }
    else if ((a.dau == 0) && (b.dau == 1)) {
        return false;
    }
    else if ((a.dau == 1) && (b.dau == 0)) {
        return false;
    }
    else if ((a.dau == 1) && (b.dau == 1)) {
        return true;
    }
    return true;
}
void make_equal(bigint& a, bigint& b) {
    int n = getlByte(b);
    int na = getlByte(a);
    while (na < n) {
        push_front(a,0);
        na++;
    }
}
int makeEqualLength(bigint& a, bigint& b) {
    int n1 = getlByte(a);
    int n2 = getlByte(b);
    if (n1 < n2) {
        make_equal(a, b);
        return n2;
    }
    else if (n1 > n2) {
        make_equal(b, a);
        return n1;
    }
    else if (n1 == n2) {
        return n1;
    }
}
bigint add_bin(bigint a, bigint b) {
    bigint res;
    int buffer = 0;
    int l = makeEqualLength(a, b);
    for (int i = l - 1; i >= 0; i--) {
        int fbit = getDigit(a, i);
        int sbit = getDigit(b, i);
        int sum = fbit ^ sbit ^ buffer;
        push_front(res,sum);
        if ((fbit == 1) && (sbit == 1)) {
            buffer = 1;
        }
        else {
            buffer = 0;
        }
    }
    if (buffer == 1) {
        push_front(res,1);
    }
    return res;
}
bigint add_dec_step(bigint a, bigint b) {
    bigint res;
    int la = getlByte(a);
    int lb = getlByte(b);
    int l = makeEqualLength(a, b);
    init(res, l);
    int buffer = 0;
    int count = 0;
    for (int i = l - 1; i >= 0; i--) {
        int fnum = getDigit(a, i);
        int snum = getDigit(b, i);
        int sum = fnum + snum + buffer;
        push_front(res,sum % 10);
        count++;
        if (sum > 10) {
            buffer = 1;
        }
        else {
            buffer = 0;
        }
        
    }
    delete_trash(res, count);
    return res;
}
bigint add_dec(bigint a, bigint b) {
    if ((a.dau == 1) && (b.dau == 1)) {
        return add_dec_step(a, b);
    }
    else if ((a.dau == 1) && (b.dau == 0)) {
        return substract(a, b);
    }
    else if ((a.dau == 0) && (b.dau == 1)) {
        return substract(b, a);
    }
    else if ((a.dau == 0) && (b.dau == 0)) {
        bigint res;
        res = add_dec_step(a, b);
        res.dau = 0;
        return res;
    }
}
bigint subtract_step(bigint a, bigint b) {
    bigint res;
    int la = getlByte(a);
    int lb = getlByte(b);
    int count = 0;
    int buffer = 0;
    int l = makeEqualLength(a, b);
    init(res, la);
    for (int i = l - 1; i >= 0; i--) {
        int fbit = getDigit(a, i);
        int sbit = getDigit(b, i);
        sbit = sbit + buffer;
        if (fbit < sbit) {
            fbit += 10;
            buffer = 1;
        }
        else {
            buffer = 0;
        }
        int sum = fbit - sbit;
        push_front(res,sum);
        count++;
    }
    delete_trash(res, count);
    return res;
}
bigint substract(bigint a, bigint b) {
    int check = compare(a, b);
    if (check == 1) {
        return subtract_step(a, b);
    }
    else if (check == 0) {
        return subtract_step(a, b);
    }
    else if (check == -1) {
        bigint res;
        res.dau = 0;
        init(res, 128);
        res = subtract_step(b, a);
        
    }
    return subtract_step(a, b);

}
void equal(bigint& a, bigint& b) {
    b.data = a.data;
    b.dau = a.dau;
}
int compare_full(bigint a, bigint b) {
    if (check_dau(a, b)) {
        if (compare(a, b) == 1) {
            return 1;
        }
        else if (compare(a, b) == -1) {
            return -1;
        }
        else if (compare(a, b) == 0) {
            return 0;
        }
    }
    else if (!check_dau(a, b)) {
        if ((a.dau == 1) && (b.dau == 0)) {
            return 1;
        }
        else if ((a.dau == 0) && (b.dau == 1)) {
            return -1;
        }
    }
}
