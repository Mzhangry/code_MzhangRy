// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int a[210], sum[210];
int f[210][210], f1[210][210];
const int mxf = 1e9;
int main() {
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) {
        cin >> a[i];
        a[i+n] = a[i];
    }
    for (int i=1;i<=n*2;i++) sum[i] = sum[i-1] + a[i];
    for (int len = 1;len<=n;len++) {
        for (int st = 1; st <= n*2+1-len; st++) {
            int ed = st + len - 1;
            if (len == 1) f[st][ed] = f1[st][ed] = 0;
            else {
                f[st][ed] = mxf;
                for (int i=st;i<ed;i++) {
                    f[st][ed] = min(f[st][ed], f[st][i] + f[i+1][ed]);
                    f1[st][ed] = max(f1[st][ed], f1[st][i] + f1[i+1][ed]);
                }
                f[st][ed] += sum[ed] - sum[st-1];
                f1[st][ed] += sum[ed] - sum[st-1];
            }
        }
    }
    int ans1 = mxf, ans2 = 0;
    for (int i=1;i<=n;i++) {
        ans1 = min(ans1, f[i][i+n-1]);
        ans2 = max(ans2, f1[i][i+n-1]);
    }
    cout << ans1 << endl << ans2 << endl;
}