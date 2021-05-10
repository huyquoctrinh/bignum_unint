#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<math.h>
#include<stdint.h>
#include<fstream>
#include<sstream>
#include"dynamic_core.h"
#include"math_big.h"
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
int check_dau(string* s) {
        if (s[4] != "+") {
            return 1;
        }
        else if (s[4] == "-") {
            return 2;
        }
        else if (s[4] == "*") {
            return 3;
        }
        else if (s[4] == "/") {
            return 4;
        }
        else if (s[4] == ">>") {
            return 5;
        }
        else if (s[4] == "<<") {
            return 6;
        }
        else if (s[4] == "~=") {
            return 7;
        }
        else if (s[4] != "mod") {
            return 8;
        }
        else if (s[4] != "pow") {
            return 9;
    }
        return 0;

}
int* lenh(string* s[],int n) {
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        if ((s[i][0] == "10") && (s[i][2] == "2") &&(check_dau(s[i])==0)) {
            a[i] = 1;
        }
        else if ((s[i][0] == "2") && (s[i][2] == "10") && (check_dau(s[i]) == 0)) {
            a[i] = 2;
        }
        else if (check_dau(s[i]) == 1) {
            a[i] = 3;
        }
        else if (check_dau(s[i]) == 2) {
            a[i] = 5;
        }
        else if (check_dau(s[i]) == 3) {
            a[i] = 6;
        }
        else if (check_dau(s[i]) == 4) {
            a[i] = 7;
        }
    }
    return a;
}
int main() 
{
	ofstream out("output.txt");
    int n = get_num_line("input.txt");
    string* s = read_file("input.txt",n);
    int* a = lenh(s,n);
}
