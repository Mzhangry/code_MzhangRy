// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int w[105], v[105];
int f[105][1005];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i=1;i<=n;i++) {
        cin >> w[i] >> v[i];
    }
    for (int i=1;i<=n;i++) {
        for (int j=0;j<=m;j++) {
            f[i][j] = f[i-1][j];
            if (w[i] <= j) f[i][j] = max(f[i][j], f[i-1][j-w[i]] + v[i]);
        }
    }
    cout << f[n][m];
}