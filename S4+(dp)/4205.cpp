// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int f[1005][1005];
int main() {
    string s, t;
    cin >> s >> t;
    int len1 = s.length(), len2 = t.length();
    for (int i=0;i<=len1;i++) {
        for (int j=0;j<=len2;j++) {
            if (i == 0 && j == 0) continue;
            else if (i==0) f[i][j] = f[i][j-1] + t[j-1];
            else if (j==0) f[i][j] = f[i-1][j] + s[i-1];
            else {
                f[i][j] = min(f[i-1][j] + s[i-1], f[i][j-1] + t[j-1]);
                if (s[i-1] == t[j-1]) f[i][j] = min(f[i][j], f[i-1][j-1]);
            }
        }
    }
    cout << f[len1][len2];
}