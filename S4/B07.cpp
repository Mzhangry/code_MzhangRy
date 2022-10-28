// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

bool a[1005][1005];
int f[1005][1005];
char s;
int main() {
    int n, m;
    cin >> n >> m;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cin >> s;
            a[i][j] = (s=='1');
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            f[i][j] = (a[i][j]!=a[i-1][j] && a[i][j]!=a[i][j-1] && a[i][j]==a[i-1][j-1]) * (min(min(f[i-1][j], f[i][j-1]), f[i-1][j-1])) + 1;
        }
    }
    int ans = 0;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            ans = max(ans, f[i][j]);
        }
    }
    cout << ans;
}