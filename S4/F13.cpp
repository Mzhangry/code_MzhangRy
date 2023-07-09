// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int w[105], v[105];
int f[105][1005], a[105][1005];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> w[i] >> v[i];
    for (int i=1;i<=n;i++) {
        for (int j=m;j>=0;j--) {
            if (w[i] > j || f[i-1][j] > f[i-1][j-w[i]] + v[i]) {
                f[i][j] = f[i-1][j];
                a[i][j] = a[i-1][j];
            } else if (f[i-1][j] < f[i-1][j-w[i]] + v[i]) {
                f[i][j] = f[i-1][j-w[i]] + v[i];
                a[i][j] = a[i-1][j-w[i]] + 1;
            } else {
                f[i][j] = f[i-1][j];
                a[i][j] = min (a[i-1][j], a[i-1][j-w[i]]+1);
            }
        }
    }
    cout << f[n][m] << ' ' << a[n][m];
}