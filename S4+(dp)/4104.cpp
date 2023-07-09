// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int a[85][85];
long long f[85][85][85];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cin >> a[i][j];
    for (int i=1;i<=n;i++) {
        for (int len = 1;len <= m;len++) {
            for (int st = 1;st <= m+1-len;st++) {
                int ed = st + len - 1;
                f[i][st][ed] = max (f[i][st+1][ed] + a[i][st]*pow(2, m-len+1), f[i][st][ed-1] + a[i][ed]*pow(2, m-len+1));
            }
        }
    }
    long long ans = 0;
    for (int i=1;i<=n;i++) ans += f[i][1][m];
    cout << ans;
}