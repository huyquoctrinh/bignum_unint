#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<math.h>
#include<stdint.h>
#include<fstream>
#include<sstream>
#include"dynamic_core.h"
#include"math_big.h"
#include<string.h>
#include"adv.h"
using namespace std;
int get_num_line(string filename) {
    ifstream f1;
    char c;
    int numchars, numlines;

    f1.open(filename);

    numchars = 0;
    numlines = 0;
    f1.get(c);
    while (f1) {
        while (f1 && c != '\n') {
            numchars = numchars + 1;
            f1.get(c);
        }
        numlines = numlines + 1;
        f1.get(c);
    }
    return numlines;
}
/*
string* content(const char* filename) {

}
*/
string* read_file(string filename,long long n) {
    ifstream file(filename);
    string* myArray = new string[n];
    long long i = 0;
    if (file.is_open()) {
        string tp;
        while (getline(file, tp)) {
            //cout << tp << "\n";
            myArray[i] = tp;
            i++;
            if (i == n) {
                break;
            }
        }
    }
    return myArray;
}
void outstring(string a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i];
    }
}
int check_dau(string s) {
   
    for (int i = 1; i < s.size()-1; i++) {
        if ((s[i - 1] ==' ') && (s[i + 1] == ' ') && (s[i] == '+')) {
            return 1;
        }
        else if ((s[i - 1] == ' ') && (s[i + 1] == ' ') && (s[i] == '-')) {
            return 2;
        }
        else if ((s[i - 1] == ' ') && (s[i + 1] == ' ') && (s[i] == '*')) {
            return 3;
        }
        else if ((s[i - 1] == ' ') && (s[i + 1] == ' ') && (s[i] == '/')) {
            return 4;
        }
        else if ((s[0] == '10') && (s[2] == '2')) {
            return 5;
        }
        else if ((s[0] == '2') && (s[2] == '10')) {
            return 6;
        }
    }
    return 0;
}

int* lenh(string* s,int n) {
    int* a = new int[n];
    for (int i = 0; i < n;i++) {
        if (check_dau(s[i])==1) {
            a[i] = 1;
        }
        else if (check_dau(s[i]) == 2) {
            a[i] = 2;
        }
        else if (check_dau(s[i]) == 3) {
            a[i] = 3;
        }
        else if (check_dau(s[i]) == 4) {
            a[i] = 4;
        }
        else if (check_dau(s[i]) == 5) {
            a[i] = 5;
        }
        else if (check_dau(s[i]) == 6) {
            a[i] = 6;
        }
        else if (check_dau(s[i]) == 0) {
            a[i] = 7;
        }
    }
    return a;
}
bigint get_bigint1(string s) {
    bigint kq;
    string res;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            for (int j = i+1; j < s.size(); j++) {
                res.push_back(s[j]);
                if (s[j] == ' ') {
                    break;
                }
            }
            break;
        }
    }
    kq = string2bigint(res);
    return kq;
}
bigint get_bigint2(string s) {
    string res;
    bigint kq;
    for (int i = s.size() - 1; i >= 0; i--) {
        res.push_back(s[i]);
        if (s[i] == ' ') {
            break;
        }
    }
    reverse(res.begin(), res.end()-1);
    kq = string2bigint(res);
    return kq;
}
void write_out(string fileout, bigint n) {
    ofstream out(fileout,ios::app);
    int l = getlByte(n);
    for (int i = 0; i < l; i++) {
        out << n.data.byte[i];
    }
    out << "\n";
}
void script(string filein,string fileout) {
    bigint a, b;
    int n = get_num_line(filein);
    string* s = read_file(filein, n);
    int* asd = lenh(s, n);
    for (int i = 0; i < n; i++) {
        bigint a = get_bigint1(s[i]);
        bigint b = get_bigint2(s[i]);
        /*
        bigint res;
        if (asd[i] == 1) {
            res = add_dec(a, b);
        }
        else if (asd[i] == 2) {
            res = substract(a, b);
        }
        else if (asd[i] == 3) {
            res = multiply(a, b);
        }
        else if (asd[i] == 4) {
            res = divide(a, 2);
        }
        */
        write_out(fileout, a);
    }
}
int main(int argc , char** argv) 
{
    //script(argv[1], argv[2]);
    bigint a, b,res;
    string a1 = "1000";
    string b1 = "100";
    a = string2bigint(a1);
    b = string2bigint(b1);
    //res = div(a, b);
    //make_equal(b,a);
    //output(res);
    string kq = to_base58(a);
    for (int i = 0; i < kq.size(); i++) {
        cout << kq[i];
    }
    //cout << l;
}
