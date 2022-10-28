// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

const int maxn = 1000 + 5;
bool a[maxn][maxn];
int f[maxn][maxn];
char s;
int main() {
    int ans = 0;
    int n, m;
    cin >> n >> m;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cin >> s;
            a[i][j] = (s == '1');
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            f[i][j] = (a[i][j]) * (min(min(f[i-1][j],f[i][j-1]),f[i-1][j-1])+1);
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            ans = max(ans, f[i][j]);
        }
    }
    cout << ans;
}