// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int a[105];
int f[205][205];
int main() {
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) {
        cin >> a[i];
        a[i+n] = a[i];
    }
    for (int len = 3;len <= n+1;len++) {
        for (int st = 1;st<=2*n+1-len;st++) {
            int ed = st + len - 1;
            for (int i=st+1;i<ed;i++) {
                f[st][ed] = max(f[st][ed], f[st][i] + f[i][ed] + a[st]*a[i]*a[ed]);
            }
        }
    }
    int ans = 0;
    for (int i=1;i<=n;i++) ans = max(ans, f[i][i+n]);
    cout << ans;
}