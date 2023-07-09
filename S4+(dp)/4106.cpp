// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int a[105];
const __int128 mxf = 1e38;
__int128 f[105][105];
void out (__int128 a) {
    if (a > 9) out(a/10);
    putchar (a%10 + '0');
}
int main() {
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) {
        cin >> a[i];
        a[i+n] = a[i];
    }
    for (int len = 3;len<=n;len++) {
        for (int st = 1;st<=2*n+1-len;st++) {
            int ed = st + len - 1;
            f[st][ed] = mxf;
            for (int i=st+1;i<ed;i++) {
                f[st][ed] = min(f[st][ed], f[st][i] + f[i][ed] + a[i]*a[st]*a[ed]);
            }
        }
    }
    __int128 ans = mxf;
    // for (int i=1;i<=n;i++) ans = min(ans, f[i][i+n]);
    for (int i=1;i<=n;i++) ans = min(ans, f[i][i+n-1]);
    out (ans);
}