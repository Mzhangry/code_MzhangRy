// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
        string s;
        int ans = 0, k = 8;
        cin >> s;
        for (int i=0;i<s.length();i++) {
            ans = ans * k + s[i] - '0';
        }
        cout << ans;
}