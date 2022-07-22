// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i=0;i<s.length();i++) {
        if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
    }
    int now = 1;
    for (int i=1;i<s.length();i++) {
        if (s[i] != s[i-1]) {
            cout << '(' << s[i-1] << ',' << now << ')';
            now = 1;
        } else {
            now ++;
        }
    }
    cout << '(' << s[s.length()-1] << ',' << now << ')';
}