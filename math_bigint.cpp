#include<iostream>
#include<string>
#include<stdint.h>
#include"dynamic_core.h"
#include"math_big.h"
#include<math.h>
#include<cstring>
#include<algorithm>
#include<string.h>
using namespace std;
//bigint::bigint() {
//}
bigint doidau(bigint& a, bool mark) {
    a.dau = mark;
    return a;
}
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
        na = getlByte(a);
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
/*
bigint add_bin(bigint a, bigint b) {
    bigint res;
    int buffer = 0;
    int l = makeEqualLength(a, b);
    init(res, l);
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
*/
bigint add_dec_step(bigint a, bigint b) {
    bigint res;
    //int la = getlByte(a);
    //int lb = getlByte(b);
    int l = makeEqualLength(a, b);
    output(a); cout << "\n"; output(b); cout << "\n";
    res = init(res, l);
    int buffer = 0;
    int count = 0;
    
    for (int i = l - 1; i >= 0; i--) {
        int fnum = getDigit(a, i);
        int snum = getDigit(b, i);
        int sum = fnum + snum + buffer;
        cout << "sum " << sum % 10 << "\n";
        push_front(res, sum % 10);
        pop_back(res);
        count++;
        if (sum >= 10) {
            buffer = 1;
        }
        else {
            buffer = 0;
        }
        cout << "buffer: " << buffer << "\n";
        cout << "count: " << count << "\n";

    }
    
    if (buffer == 1) {
        push_front(res, 1);
    }
    
    
    cout << buffer << "\n";
    //delete_trash(res, count);
    return res;
}
bigint add_dec(bigint a, bigint b) {
    bigint res;
    if ((a.dau == 1) && (b.dau == 1)) {
        res = add_dec_step(a, b);
        doidau(res, true);
        return res;
    }
    else if ((a.dau == true) && (b.dau == 0)) {
        return substract(a, b);
    }
    else if ((a.dau == 0) && (b.dau == true)) {
        return substract(b, a);
    }
    else if ((a.dau == 0) && (b.dau == 0)) {   
        res = add_dec_step(a, b);
        doidau(res, 0);
        return res;
    }
}
bigint subtract_step(bigint a, bigint b) {
    bigint res;
    int count = 0;
    int buffer = 0;
    int l = makeEqualLength(a, b);
    res = init(res, l);
    for (int i = l - 1; i >= 0; i--) {
        int fbit = getDigit(a, i);
        int sbit = getDigit(b, i);
        sbit = sbit + buffer;
        //cout<<"fbit "<<fbit<<"sbit "<<sbit<<"buffer "<<buffer<<"\n";
    
        if (fbit < sbit) {
            fbit += 10;
            buffer = 1;
        }
        else {
            buffer = 0;
        }
        int diff = fbit - sbit;
        //cout<<"diff "<<diff<<"\n";
        push_front(res,diff);
        pop_back(res);
        count++;
    }
    //cout<<"count: "<<count;
    free(a.data.byte);
    free(b.data.byte);
    //delete_trash(res, count);
    res = remove_zero(res);
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
        int l = getlByte(b);
        init(res, l);
        res = subtract_step(b, a);
        doidau(res, false);
        return res;
        
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
bigint reverse(bigint a) {
    int l = getlByte(a);
    bigint res;
    init(res, l);
    for (int i = 0; i < l; i++) {
        res.data.byte[i] = a.data.byte[l - i-1];
    }
    return res;
}
bigint multiply(bigint a, bigint b) {
    int l1 = getlByte(a);
    int l2 = getlByte(b);
    bigint res;
    init(res, l1 + l2);
    

    int i_n1 = 0;
    int i_n2 = 0;
    for (int i = l1 - 1; i >= 0; i--)
    {
        int buffer = 0;
        int n1 = getDigit(a, i);
        i_n2 = 0;
        for (int j = l2 - 1; j >= 0; j--)
        {
            int n2 = getDigit(b, j);
            int sum = n1 * n2 + res.data.byte[i_n1 + i_n2] + buffer;
            buffer = sum / 10;
            res.data.byte[i_n1 + i_n2] = sum % 10;
            i_n2++;
        }
        if (buffer > 0)
            res.data.byte[i_n1 + i_n2] += buffer;
        i_n1++;
    }
    int i = getlByte(res)-1 ;
    while (i >= 0 && res.data.byte[i] == 0)
        i--;
    if (i == -1) {
        bigint r;
        init(r, 1);
        return r;
    }
    pop_back(res);
    res = reverse(res);
    if ((a.dau == 0) && (b.dau == 0)) {
        doidau(res, true);
    }
    else if ((a.dau == 0) && (b.dau == 1)) {
        doidau(res, false);
    }
    else if ((a.dau == 1) && (b.dau == 0)) {
        doidau(res, false);
    }
    else if ((a.dau == 1) && (b.dau == 1)) {
        doidau(res, true);
    }
    //push_back(res, 0);
    /*
    res.data = result;
    res.data.pop_back();
    reverse(res.data.begin(), res.data.end());
    */
    return res;
}

unsigned long long bin2dec(bigint n) {
    unsigned long long dec_value = 0;
    int base = 1;

    int len = getlByte(n);
    for (int i = len - 1; i >= 0; i--) {
        if (n.data.byte[i] == 1)
            dec_value += base;
        base = base * 2;
    }

    return dec_value;
}
int bitshift_right(bigint a, int unit) {
    int l = getlByte(a);
    for (int i = 0; i < unit; i++) {
        pop_back(a);
    }
    int kq = bin2dec(a);
    return kq;
}
int bitshift_left(bigint a, int unit) {
    int l = getlByte(a);
    for (int i = 0; i < unit; i++) {
        pop_front(a);
        push_back(a,0);
    }
    int kq = bin2dec(a);
    return kq;
}
int mod(bigint a, int n)
{
    int res = 0;
    int l = getlByte(a);
    for (int i = 0; i < l; i++)
        res = (res * 10 + getDigit(a, i)) % n;

    return res;
}
bigint mod_big(bigint a, bigint x)
{
    bigint abc;
    int n = bigint2int(x);
    int res = 0;
    int l = getlByte(a);
    for (int i = 0; i < l; i++)
        res = (res * 10 + getDigit(a, i)) % n;
    abc = int2bigint(res);
    return abc;
}
bigint divide_step(bigint number, int divisor)
{
    bigint res;
    int l = getlByte(number);
    init(res, l);
    int idx = 0;
    int count = 0;
    int temp = getDigit(number, idx);
    while (temp < divisor) {
        ++idx;
        if (getDigit(number, idx) == -1) {
            init(res, 1);
            res.data.byte[0] = temp / divisor ;
            return res;
        }
        temp = temp * 10 + getDigit(number, idx);

    }
    while (getlByte(number) > idx) {
        push_back(res,temp / divisor);
        count++;
        ++idx;
        if (getDigit(number, idx) == -1) {
            return res;
        }
        temp = temp % divisor * 10 + getDigit(number, idx);

    }
    if (getlByte(res) == 0) {
        res.data.byte = { 0 };
        return res;
    }
    cout << count;
    delete_trash(res, count);
    return res;
}
bigint divide(bigint a, int divisor) {
    bigint res;
    res = divide_step(a, divisor);
    if ((a.dau == 0) && (divisor < 0)) {
        res.dau = 1;
    }
    else if ((a.dau == 0) && (divisor > 0)) {
        res.dau = 0;
    }
    else if ((a.dau == 1) && (divisor < 0)) {
        res.dau = 0;
    }
    else if ((a.dau == 1) && (divisor > 0)) {
        res.dau = 1;
    }
    return res;
}
bigint dec2bin(bigint n) {
    int l = getlByte(n);
    bigint res, tmp;
    init(tmp, l);
    init(res, l);
    int count = 0;
    while (compare(n, tmp) == 1) {
        push_front(res,mod(n, 2));
        count++;
        n = divide(n, 2);
    }
    //cout << count << "\n";
    delete_trash(res, 2);
    /*
    if (n.dau == 0) {
        bigint kq;
        init(kq, l + 1);
        kq = twoComplement(res);
        return kq;
    }
    */
    return res;
}
bigint addBinary(bigint a, bigint b)
{
    bigint res;
    int s = 0; 
    int l = makeEqualLength(a, b);
    init(res, l);
    
    int buffer = 0;
    for (int i = l - 1; i >= 0; i--) {
        int fbit = getDigit(a, i);
        int sbit = getDigit(b, i);
        int sum = (fbit ^ sbit ^ buffer);
        cout << "fbit: " << fbit << "sbit: " << sbit << "\n";
        cout <<"sum: "<< sum <<" "<<"buffer: "<<buffer<< "\n";
        push_front(res, sum);
        pop_back(res);
        if ((fbit == 1) && (sbit == 1)) {
            buffer = 1;
        }
        else if ((fbit ==1) && (sbit==0)&& (buffer==1)) {
            buffer = 1;
        }
        else if ((fbit == 0) && (sbit == 1) && (buffer == 1)) {
            buffer = 1;
        }
        else {
            buffer = 0;
        }
    }
    cout << buffer<<"\n";
    if (buffer == 1) {
        push_front(res, 1);
    }
    
    return res;
}
bigint not_op(bigint a) {
    bigint res;
    int l = getlByte(a);
    init(res, l);
    for (int i = 0; i < l; i++) {
        if (a.data.byte[i] == 1) {
            res.data.byte[i] = 0;
        }
        else {
            res.data.byte[i] = 1;
        }
        
    }
    return res;
}
unsigned long long not_op_dec(bigint a) {
    bigint res;
    res = not_op(a);
    unsigned long long kq = bin2dec(res);
    return kq;
}
bigint twoComplement(bigint a)
{
    bigint result;
    result = a;
    bool flag = false;
    int l = getlByte(result);
    for (int i = l - 1; i > 0 && flag != true; i--)
    {
        if (result.data.byte[i] == 1)
        {
            for (int j = i - 1; j > 0; j--)
                result.data.byte[j] = (result.data.byte[j] == 0) ? 1 : 0;
            flag = true;
        }
    }

    result.data.byte[0] = 1;
    return result;
}
bigint div(bigint a, bigint b)
{
    int la = getlByte(a);
    int lb = getlByte(b);
    bigint res;
    init(res, la);
    res = a;
    int comp = 2;
    bigint count, one;
    init(count, la);
    count.dau = 1;
    init(one, 1);
    one.dau = 1;
    one.data.byte[0] = 1;
    output(one);
    cout << "\n";
    //output(count);
   count = add_dec(count, one);
    output(count);
    
    while ((comp != 0) && (comp != -1))
    {
        comp = compare_full(res, b);
        if (comp == 0)
            break;

        res = substract(res, b);
        count = add_dec(count, one);
    }
    count = add_dec(count, one);

    //output(res);
    return count;
}


char reVal(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}
void strev(char* str)
{
    int len = strlen(str);
    int i;
    for (i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}
char* fromDeci(char res[], int base, int inputNum)
{
    int index = 0;
    while (inputNum > 0)
    {
        res[index++] = reVal(inputNum % base);
        inputNum /= base;
    }
    res[index] = '\0';
    strev(res);

    return res;
}
