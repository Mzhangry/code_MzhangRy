// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int a[305];
int f[305][305];
int sum[305];
const int mxf = 1e8;
int main() {
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) sum[i] = sum[i-1] + a[i];
    for (int len = 1;len <= n;len ++) {
        for (int st = 1;st <= n+1 - len;st++) {
            int ed = st + len - 1;
            if (len == 1) f[st][ed] = 0;
            else {
                f[st][ed] = mxf;
                for (int i=st;i<ed;i++) {
                    f[st][ed] = min(f[st][ed], f[st][i] + f[i+1][ed]);
                }
                f[st][ed] += sum[ed] - sum[st-1];
            }
        }
    }
    cout << f[1][n];
}