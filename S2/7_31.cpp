// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    string s;
    int now = 1;
    cin >> s;
    for (int i=1;i<s.length();i++) {
        if (s[i] != s[i-1]) {
            cout << now << s[i-1];
            now = 1;
        } else {
            now ++;
        }
    }
    cout << now << s[s.length()-1];
}