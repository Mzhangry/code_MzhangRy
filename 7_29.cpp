// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int k=0, sum = 0;
    for (int i=0;i<=10;i++) {
        if (i==1||i==5) continue;
        k++;
        sum += (s[i] - '0') * k;
    }
    if (sum % 11 == s[12] - '0' || sum % 11 == 10 && s[12] == 'X') cout << "Right";
    else {
        for (int i=0;i<=11;i++) cout << s[i];
        if (sum % 11 == 10) cout << 'X';
        else cout << sum % 11;
    }
}