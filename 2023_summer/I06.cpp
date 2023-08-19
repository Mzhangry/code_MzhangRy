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

int n, m;
int main() {
    cin >> n >> m;
    vector< vector<int> > e(n+1, vector<int> (m+1)), flu(n+2, vector<int> (m+2)), fru(n+2, vector<int> (m+2)), fld(n+2, vector<int> (m+2)), frd(n+2, vector<int> (m+2));
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cin >> e[i][j];

    for (int i=0;i<=n+1;i++) flu[i][0] = fru[i][0] = fld[i][0] = frd[i][0] = -1e9;
    for (int i=0;i<=m+1;i++) flu[0][i] = fru[0][i] = fld[0][i] = frd[0][i] = -1e9;
    for (int i=0;i<=n+1;i++) flu[i][m+1] = fru[i][m+1] = fld[i][m+1] = frd[i][m+1] = -1e9;
    for (int i=0;i<=m+1;i++) flu[n+1][i] = fru[n+1][i] = fld[n+1][i] = frd[n+1][i] = -1e9; 
    flu[0][1] = fru[0][m] = fld[n][0] = frd[n][m+1] = 0;
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) flu[i][j] = max(flu[i-1][j], flu[i][j-1]) + e[i][j];
    for (int i=1;i<=n;i++) for (int j=m;j>=1;j--) fru[i][j] = max(fru[i-1][j], fru[i][j+1]) + e[i][j];
    for (int i=n;i>=1;i--) for (int j=1;j<=m;j++) fld[i][j] = max(fld[i+1][j], fld[i][j-1]) + e[i][j];
    for (int i=n;i>=1;i--) for (int j=m;j>=1;j--) frd[i][j] = max(frd[i+1][j], frd[i][j+1]) + e[i][j];

    vector< vector<int> > sumh(n+1, vector<int> (m+1)), sums(n+1, vector<int> (m+1));
    // 前缀和
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) sumh[i][j] = sumh[i][j-1] + e[i][j];
    for (int j=1;j<=m;j++) for (int i=1;i<=n;i++) sums[i][j] = sums[i-1][j] + e[i][j];

    // 横向的重叠
    ll ans = -1e9;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            for (int k=j+1;k<=m;k++) {
                ll mx = max (flu[i-1][j] + fld[i][j-1], max(flu[i-1][j] + fld[i+1][j], fld[i+1][j] + flu[i][j-1])) + e[i][j];
                mx += max (fru[i-1][k] + frd[i][k+1], max(fru[i][k+1] + frd[i+1][k], fru[i-1][k] + frd[i+1][k])) + e[i][k];
                // if (ans < mx + sumh[i][k-1] - sumh[i][j]) cout << i << " " << j << " " << k  << ' ' << mx + sumh[i][k-1] - sumh[i][j] << endl;
                ans = max (ans, mx + sumh[i][k-1] - sumh[i][j]);
            }
        }
    }

    // 竖向的重叠
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            for (int k=j+1;k<=n;k++) {
                ll mx = max (flu[j-1][i] + fru[j][i+1], max(flu[j][i-1] + fru[j][i+1], flu[j][i-1] + fru[j-1][i])) + e[j][i];
                mx += max (fld[k+1][i] + frd[k][i+1], max(fld[k][i-1] + frd[k][i+1], fld[k][i-1] + frd[k+1][i])) + e[k][i];
                // if (ans < mx + sums[k-1][i] - sums[j][i]) cout << i << " " << j << " " << k  << ' ' << mx + sums[k-1][i] - sums[j][i] << endl;
                ans = max (ans, mx + sums[k-1][i] - sums[j][i]);
            }
        }
    }

    // 单点
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            ll mx = max (1LL*flu[i-1][j] + fld[i][j-1] + fru[i][j+1] + frd[i+1][j], 1LL*flu[i][j-1] + fld[i+1][j] + fru[i-1][j] + frd[i][j+1]);
            ans = max (ans, mx + e[i][j]);
        }
    }
    cout << ans << endl;
}