// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int w[1005], x[1005], y[1005];
int f[1000][1000]; // 制作i j克需要的最低价钱
int main() {
    // freopen("f17.out", "w", stdout);
    int n, a, b;
    cin >> n >> a >> b;
    for (int i=0;i<=600;i++) {
        for (int j=0;j<=600;j++) {
            f[i][j] = -1;
        }
    }
    f[0][0] = 0;
    for (int i=1;i<=n;i++) cin >> x[i] >> y[i] >> w[i];
    for (int i=1;i<=n;i++) {
        for (int j=300;j>=0;j--) {
            if (x[i] > j) x[i] = j;
            for (int k=300;k>=0;k--) {
                if (y[i] > k) y[i] = k;
                if (f[j-x[i]][k-y[i]] != -1) {
                    if (f[j][k] == -1) f[j][k] = f[j-x[i]][k-y[i]] + w[i];
                    else f[j][k] = min(f[j][k], f[j-x[i]][k-y[i]] + w[i]);
                }
            }
        }
    }
    int ans = 2147483640;
    for (int i=a;i<=600;i++) {
        for (int j=b;j<=600;j++) {
            if (f[i][j] == -1) continue;
            ans = min(ans, f[i][j]);
        }
    }
    cout << ans;
}