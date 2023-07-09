// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int f[2][105];
int mod = 1e9+7;
int main() {
    int n, m;
    cin >> n >> m;
    int a;
    cin >> a;
    if (a == 0) for (int i=1;i<=m;i++) f[0][i] = 1;
    else f[0][a] = 1;
    for (int i=2;i<=n;i++) {
        cin >> a;
        for (int j=1;j<=m;j++) {
            if (a!=j && a!=0) continue;
            for (int d=-1;d<=1;d++) {
                int pre = j + d;
                if (pre >= 1 && pre <= m) 
                    f[1][j] = (f[0][pre] + f[1][j]) % mod;
            }
        }
        memcpy (f[0], f[1], sizeof(f[0]));
        memset (f[1], 0, sizeof(f[1]));
    }
    int ans = 0;
    for (int i=1;i<=m;i++) ans = (ans + f[0][i]) % mod;
    cout << ans;
}