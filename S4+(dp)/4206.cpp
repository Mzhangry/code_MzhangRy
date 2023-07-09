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
    string s;
    cin >> s;
    int len = s.length();
    for (int i=1;i<=len;i++) {
        for (int j=len;j>=1;j--) {
            if (s[i-1] == s[j-1]) f[i][j] = f[i-1][j+1] + 1;
            f[i][j] = max(f[i][j], max(f[i-1][j], f[i][j+1]));
        }
    }
    cout << f[len][1];
}