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
        else if ((s[0] == '1') && (s[2] == '2')) {
            return 5;
        }
        else if ((s[0] == '2') && (s[2] == '1')) {
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
    string a1 = "100312309281381290381290381290381290812098319013212312393128903213129803129083890121238093891201238909123812309312890123898012391238901239089123802390189023819123801389021238902391801238901239238018901238903129238019123801928238913290112389012389023918023190812390812389012389012380932893128901230891238039128901231238901238093129123801238903128908973454352425036734576345673456728456738564726745823647835645738345672896724893563478925645783943567899345678468935273469257867892345456789234623578946734234209823489023490823498023489023489023489023489048902389023489023489023423490889235634578296457892324567938019089080990889090889089090889098089090889089090767623890390128312890239018128902389013912802301893128903128902318903128901238901238908902e12389013128902318902318902318901238901238091230891238901238931238912089012318902312308991380212389012389039012838901212302913812038129038129038129038123901283901283901283123781293712983712893712893712308129381290381290381123987123978123789123789312789231789123897231789123789891237381279812379789123789123123892093812903812908";
    string b1 = "10312312309123812382193812903812390012823109381209812093812093812903812093821234423342341234213419802727272727272727274982723478983479490239034808923410123489489023134890292348013480129234890123418908904312890348901341489033890124348901291348023901248349128023489013412890341290834128902341890123489034129083490128490123812348902348901349012889123409031238901239801329081289012390812380123931289012390812390818902390123890312923801918023309378248793978234189473894737834922348972493783497842342389742378923478923489723489234782347923478972489343789223789782934234789234789234789234789243879243879237894892324783928349234892348923487923487942389742398723489723478942378923489234789723448923723478942389248379234789234812341234412341392841321289123478993482747368267494567824635784568294567924789023549357820478023507823457804523704583703458780467934346712679342346791842367916134792123467967934679341267349128673412463718243126786793481239467812392467186793412796341267934126973412679823146738921412331231212312321321312312312312323113231293921831";
    a = string2bigint(a1);
    b = string2bigint(b1);
    res = add_dec(a, b);
    //make_equal(b,a);
    output(a);
    //cout << l;
}
