// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int m;
int a[105]; // a砝码重
int k, mx;
int n;
int g[10005], cntmx[10005]; // cntmx表示该克重所用的砝码k的个数
int main() {
    cin >> n >> m >> k >> mx;
    for (int i=1;i<=n;i++) g[i] = 100000;
    for (int i=1;i<=m;i++) {
        cin >> a[i];
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (i-a[j] < 0) continue;
            if (j == k) { // 是特殊砝码
                if (cntmx[i-a[j]] < mx && g[i-a[j]] + 1 < g[i]) { // 还有剩余且更少
                    g[i] = g[i-a[j]] + 1;
                    cntmx[i] = cntmx[i-a[j]] + 1;
                }
            } else {
                if (g[i-a[j]] + 1 < g[i]) {
                    g[i] = g[i-a[j]] + 1;
                    cntmx[i] = cntmx[i-a[j]];
                }
            }
        }
    }
    if (g[n] == 100000) cout << -1;
    else cout << g[n];
    // for (int i=0;i<=n;i++) cout << i << ' ' << g[i] << ' ' << cntmx[i] << endl;
}
