// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    string S,s[105];
    int num=0;
    getline(cin, S);
    S += ' ';
    for (int i=0;i<S.length();i++) {
        if (S[i] == ' ') num++;
        else s[num] += S[i];
    }
    for (int i=num-1;i>=0;i--) cout << s[i] << ' ';
}