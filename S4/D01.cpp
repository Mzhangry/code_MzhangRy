// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int n, m, k,mo = 5000011;
int f[10005][1005];
int main() {
    cin >> n >> m >> k;
    for (int i=1;i<=k+1;i++) {
        f[i][0] = 1;
        f[i][1] = i;
    }
    for (int i=k+2;i<=n;i++) {
        for (int j=0;j<=m;j++) {
            f[i][j] = (f[i-1][j] + f[i-1-k][j-1]) % mo;
        }
    }
    cout << f[n][m];
}