// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;

const int mod = 998244353;
int n, m;
bool e[2005][2005];
ll f[2005][2005][2];
// ll fastpower (int a, int b) {
//     ll ans = 1;
//     while (b) {
//         if (b & 1) ans = ans * a % mod;
//         a = a * a % mod;
//         b >>= 1;
//     }
//     return ans;
// }
int main() {
    cin >> n >> m;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            char c; cin >> c;
            if (c == '#') e[i][j] = true;
        }
    }

    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            bool flag = false;
            if (e[i][j]) {
                for (int k=j;k<=m;k++) {
                    e[i][k] = true;
                }
                flag = true;
            }
            if (flag) break;
        }
    }
    for (int j=1;j<=m;j++) {
        for (int i=1;i<=n;i++) {
            bool flag = false;
            if (e[i][j]) {
                for (int k=i;k<=n;k++) {
                    e[k][j] = true;
                }
                flag = true;
            }
            if (flag) break;
        }
    }
    // ll cnt = 0;
    // for (int i=1;i<=n;i++) {
    //     for (int j=1;j<=m;j++) {
    //         if (!e[i][j]) cnt++;
    //     }
    // }
    // ll ans = 0;
    // ans = fastpower(2, cnt);

    // for (int i=n;i>=1;i--) {
    //     for (int j=m;j>=1;j--) {
    //         f[i][j][0] = (f[i+1][j][0] + f[i][j+1][0] + f[i+1][j][1] + f[i][j+1][1]) % mod;
    //         if (!e[i][j] && ((e[i][j+1] && e[i+1][j]) || (i==n && e[i][j+1]) || (j==m && e[i+1][j]) || (i==n && j==m))) {
                
    //         }
    //     }
    // }
    for (int i=1;i<=n+1;i++) for (int j=1;j<=m+1;j++) f[i][j][1] = 1;
    if (e[n][m]) f[n][m][1] = 1;
    else f[n][m][0] = f[n][m][1] = 1;
    for (int d=2;d<=max (n, m);d++) {
        int stx = n-d+1, sty = m-d+1;
        if (!(stx < 1)) {
            for (int i=n;i>stx;i--) {
                if (e[i][sty]) f[i][sty][1] = (f[i+1][sty][1] + f[i+1][sty][0]) * (f[i][sty+1][0] + f[i][sty+1][1]) % mod;
                else f[i][sty][0] = (f[i+1][sty][1] + f[i+1][sty][0] + f[i][sty+1][0] + f[i][sty+1][1]) % mod;
                if (!e[i][sty]) f[i][sty][1] += (f[i+1][sty][1]) * (f[i][sty+1][1]) % mod;
            }
        }
        if (!(sty < 1)) {
            for (int j=m;j>sty;j--) {
                if (e[stx][j]) f[stx][j][1] = ((f[stx+1][j][1] + f[stx+1][j][0])%mod * (f[stx][j+1][0] + f[stx][j+1][1])%mod) % mod;
                else f[stx][j][0] = (f[stx+1][j][1] + f[stx+1][j][0] + f[stx][j+1][0] + f[stx][j+1][1]) % mod;
                if (!e[stx][j]) f[stx][j][1] += (f[stx+1][j][1]) * (f[stx][j+1][1]) % mod;
            }
        }
        if (e[stx][sty]) f[stx][sty][1] = (f[stx+1][sty][1] + f[stx+1][sty][0]) * (f[stx][sty+1][0] + f[stx][sty+1][1]) % mod;
        else f[stx][sty][0] = (f[stx+1][sty][1] + f[stx+1][sty][0] + f[stx][sty+1][0] + f[stx][sty+1][1]) % mod;
        if (!e[stx][sty]) f[stx][sty][1] += (f[stx+1][sty][1]) * (f[stx][sty+1][1]) % mod;
    }
    cout << f[1][1] << endl;
}