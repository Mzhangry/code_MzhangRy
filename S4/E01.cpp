// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int n, m;
long long f[55][10];
int main() {
    cin >> n >> m;
    f[0][0] = 1;
    for (int i=1;i<=n;i++) {
        for (int j=0;j<m;j++) f[i][0] += f[i-1][j];
        for (int j=1;j<m;j++) f[i][j] = f[i-1][j-1];
    }
    long long ans = 0;
    for (int i=0;i<m;i++) ans += f[n][i];
    cout << ans;
}