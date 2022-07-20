// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    string s;
    int c=0;
    getline (cin,s);
    s+=' ';
    for (int i=0;i<s.length();i++) {
        if (s[i] == ' ') {
            for (int j=i-1;j>=c;j--) cout << s[j];
            c = i+1;
            cout << ' ';
        } else {
            if (s[c] == ' ') c = i;
        }
    }
}