// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    string s;
    int cnt = 0;
    cin >> s;
    for (int i=0;i<s.length();i++) if (s[i] >= 'A' && s[i] <= 'Z') cnt ++;
    cout << cnt;
}