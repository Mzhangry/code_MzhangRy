// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int x[1005], y[1005], w[1005];
int f[305][305];
int mxm = 1e8;
int main() {
    int n, a, b;
    cin >> n >> a >> b;
    for (int i=1;i<=n;i++) cin >> x[i] >> y[i] >> w[i];
    for (int i=0;i<=a;i++) for (int j=0;j<=b;j++) f[i][j] = mxm;
    f[0][0] = 0;
    for (int i=1;i<=n;i++) {
        for (int j=a;j>=0;j--) {
            for (int k=b;k>=0;k--) {
                int x1 = (j + x[i] > a ? a : j + x[i]), y1 = (k + y[i] > b ? b : k + y[i]);
                f[x1][y1] = min (f[x1][y1], f[j][k] + w[i]);
            }
        }
    }
    cout << f[a][b];
}