// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int m, n;
int f[2505][55];
int mo = 998244353;
int main() {
    cin >> n >> m;
    f[0][0] = 1;
    for (int j=1;j<=n;j++) {
        for (int i=1;i<=m;i++) {
            f[i][j] = f[i-1][j-1];
            if (i>=2) f[i][j] = (f[i][j] + f[i-2][j-1]) % mo;
        }
    }
    int ans = 0;
    for (int i=0;i<=m;i++) ans = (ans + f[i][n]) % mo;
    cout << ans;
}