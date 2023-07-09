// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

bool f[105][105];
int main() {
    string s;
    while (getline(cin, s)) {
        for (int i=0;i<=100;i++) for (int j=0;j<=100;j++) f[i][j] = false;
        for (int i=0;i<s.length();i++) if (s[i] == '0' || s[i] == '1') f[i][i] = true;
        for (int len = 2;len<=s.length();len++) {
            for (int st = 0;st<=s.length()-len;st++) {
                int ed = st + len - 1;
                if (s[st] == '(' && s[ed] == ')' && f[st+1][ed-1]) f[st][ed] = true;
                if (s[ed] == '*' && f[st][ed-1]) f[st][ed] = true;
                for (int i=st;i<ed;i++) {
                    if (s[i] == '|') {
                        if (i != st && f[st][i-1] && f[i+1][ed]) f[st][ed] = true;
                    } else {
                        if (f[st][i] && f[i+1][ed]) f[st][ed] = true;
                    }
                } 
            }
        } 
        if (f[0][s.length()-1]) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}