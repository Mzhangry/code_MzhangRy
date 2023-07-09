// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int a[1005];
int sum[1005], f[1005][1005];
int main() {
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) sum[i] = sum[i-1] + a[i];
    for (int len = 1;len <= n;len++) {
        for (int st = 1;st <= n+1-len;st++) {
            int ed = st + len - 1;
            f[st][ed] = max (a[st] + sum[ed] - sum[st] - f[st+1][ed],
                            a[ed] + sum[ed-1] - sum[st-1] - f[st][ed-1]);
        }
    }
    cout << f[1][n];
}