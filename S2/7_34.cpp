// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    string s,s1 = "";
    cin >> s;
    for (int i=2;i<=s.length();i++) {
        for (int j=0;j<s.length()-i+1;j++) {
            s1 = "";
            for (int k=0;k<i;k++) {
                s1 += s[j+k];
            }
            int k;
            for (k=0;2*k<=i;k++) {
                if (s1[k] != s1[i-k-1]) break;
            }
            if (2*k>i) cout << s1 << endl;
        }
    }
}