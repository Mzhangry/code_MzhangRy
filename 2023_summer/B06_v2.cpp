// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int inf = 1e9;
int n, m;
int a[1005];
int f[1005][1005];
int main() {
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=0;i<=n;i++) for (int j=0;j<=m;j++) f[i][j] = inf;
    f[0][0] = f[1][0] = 0;
    for (int i=2;i<=n;i++) {
        for (int j=0;j<i;j++) {
            // int ans = 1e9;
            for (int k=i-1;k>=0 && i-k-1<=j;k--) {
                if (k == 0) a[0] = a[i];
                f[i][j] = min (f[i][j], max (f[k][j-(i-k-1)], abs(a[i] - a[k]) % (i-k) == 0? abs(a[i] - a[k]) / (i-k) : abs(a[i] - a[k]) / (i-k) + 1));
            }
        }
    }
    int ans = 1e9;
    for (int i=1;i<=n;i++) {
        for (int j=0;m-j >= n-i;j++) {
            // cout << i << ' ' << j << ' '<< f[i][j] << ' ';
            ans = min(f[i][j], ans);
        }
        // cout << endl;
    }
    cout << ans << endl;
}