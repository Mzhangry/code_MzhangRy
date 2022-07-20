// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    string s,a[105],tmp;
    int num=0;
    getline (cin,s);
    s+=' ';
    for (int i=0;i<s.length();i++) {
        if (s[i] == ' ') {
            if (a[num].length() != 0) num++;
        } else {
            a[num] += s[i];
        }
    }
    for (int i=0;i<num-1;i++) {
        for (int j=0;j<num-1;j++) {
            if (a[j] > a[j+1]) {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
    cout << a[0] << endl;
    for (int i=1;i<num;i++) {
        if (a[i] != a[i-1]) cout << a[i] << endl;
    }
    return 0;
}