// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int a, b;
    string s;
    cin >> a >> s >> b;
    long long ten = 0;
    for (int i=0;i<s.length();i++) {
        if (s[i] >= 'a' && s[i] <= 'z') ten = ten * a + s[i] - 'a' + 10;
        else if (s[i] >= 'A' && s[i] <= 'Z') ten = ten * a + s[i] - 'A' + 10;
        else ten = ten * a + s[i] - '0';
    }
    int y[100000], m = 0;
    while (ten > 0) {
        y[m] = ten % b;
        ten /= b;
        m++;
    }
    for (int i=m-1; i>=0; i--) {
        if (y[i] >= 10) cout << char (y[i] - 10 + 'A');
        else cout << y[i];
    }
    if (m == 0) cout << 0;
}