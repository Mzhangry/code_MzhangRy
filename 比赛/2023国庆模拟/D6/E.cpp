// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int inf = 1e9 + 10;
int main() {
    int t; cin >> t;
    while (t--) {
        int n, K, m, h; cin >> n >> K >> m >> h;
        vector<int> a(n+1), b(n+1), c(n+1);
        for (int i=1;i<=n;i++) cin >> a[i] >> b[i] >> c[i];
        vector< vector<int> > f(m+1, vector<int> (K+1, inf));
        f[m][K] = h;
        bool flag0 = false;
        for (int i=1;i<=n;i++) {
            vector< vector<int> > fa(m+1, vector<int> (K+1, inf));
            bool flag = false;
            for (int j=1;j<=m;j++) {
                for (int k=0;k<=K;k++) {
                    // 打
                    if (f[j][k] - b[i] <= 0) flag  = flag0 = true;
                    if (j + a[i] <= m && f[j+a[i]][k] != inf) fa[j][k] = min(fa[j][k], f[j+a[i]][k] - b[i]);
                    // 回
                    if (j + a[i] <= m && j + a[i] - c[i] >= 1) fa[j][k] = min(fa[j][k], f[j+a[i]-c[i]][k]);
                    if (j == m - a[i]) for (int p = max(1, m-c[i]);p<=m;p++) fa[j][k] = min(fa[j][k], f[p][k]);
                    // 卡
                    if (k + 1 <= K) fa[j][k] = min(fa[j][k], f[j][k+1]);

                }
            }
            if (flag) {cout << i << endl; break;}
            f = fa;
        }
        if (!flag0) cout << "Fail" << endl;
    }
}