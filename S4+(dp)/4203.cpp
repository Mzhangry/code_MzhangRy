// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

bool f[25][25];
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int len1 = s1.length(), len2 = s2.length();
    f[0][0] = true;
    for (int i=1;i<=len1;i++) f[i][0] = f[i-1][0] & (s1[i-1] == '*');
    for (int i=1;i<=len1;i++) {
        for (int j=1;j<=len2;j++) {
            if ((s1[i-1] == s2[j-1] || s1[i-1] == '?') && f[i-1][j-1]) f[i][j] = true;
            else if (s1[i-1] == '*') {
                for (int k=0;k<=j;k++) {
                    if (f[i-1][k]) f[i][j] = true;
                }
            } 
        }
    }
    if (f[len1][len2]) cout << "matched";
    else cout << "not matched";
}