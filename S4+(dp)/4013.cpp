// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

struct Book {
    int h, w;
    bool operator < (const Book & r) const{
        return h < r.h;
    }
};
const int mxw = 100000;
int f[105][105];
Book a[105];
int main() {
    int n, k;
    cin >> n >> k;
    for (int i=1;i<=n;i++) cin >> a[i].h >> a[i].w;
    for (int i=0;i<=n;i++) 
        for (int j=0;j<=n;j++) 
            f[i][j] = mxw;
    f[0][0] = 0;
    sort (a+1, a+n+1);
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=i && j<=n-k;j++) {
            for (int p=j-1;p<i;p++) {
                f[i][j] = min(f[i][j], f[p][j-1] + abs(a[i].w - (p == 0 ? a[i].w : a[p].w)));
            }
        }
    }
    int ans = mxw;
    for (int i=n-k;i<=n;i++) ans = min(ans, f[i][n-k]);
    cout << ans;
}