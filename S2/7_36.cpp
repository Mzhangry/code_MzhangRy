// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    s += ' ';
    int ans = 0;
    for (int i=1;i<s.length();i++) {
        if (s[i] == ' ' && s[i-1] != ' ') ans++;
    }
    cout << ans;
}