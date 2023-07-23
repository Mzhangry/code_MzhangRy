// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int n;
char s[200005];
int f[200005][3];
int main() {
    cin >> n;
    for (int i=1;i<=n;i++) {
        cin >> s[i];
    }
    s[0] = s[1]; f[0][1] = f[0][2] = 0;
    for (int i=1;i<=n;i++) {
        if (s[i] == s[i-1]) {
            f[i][1] = f[i-1][1];
            f[i][2] = f[i-1][2];
        } else {
            f[i][1] = i-1;
            if (s[i] == s[f[i-1][1]]) f[i][2] = f[i-1][2];
            else f[i][2] = f[i-1][1];
        }
    }
    long long ans = 0;
    for (int i=1;i<=n;i++) ans += i - f[i][2];
    cout << ans;
}