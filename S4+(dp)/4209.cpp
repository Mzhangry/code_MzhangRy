// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int f[1005][1005];
const int inf = 1e5;
int main() {
    string s, t;
    cin >> s >> t;
    int len1 = s.length(), len2 = t.length();
    for (int i=1;i<=len2;i++) f[0][i] = inf;
    for (int i=1;i<=len1;i++) {
        for (int j=1;j<=len2;j++) {
            f[i][j] = f[i-1][j];
            if (s[i-1] != t[j-1]) f[i][j] = min(f[i][j], f[i-1][j-1]+1);
            else f[i][j] = min(f[i][j], f[i-1][j-1]);
        }
    }
    cout << f[len1][len2];
}