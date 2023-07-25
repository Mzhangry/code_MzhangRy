// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<double, double> P;
const int inf = 1e9;

int n;
double f[1<<20][20];
P xy[20];
double dis[20][20];
double caldis (P a, P b) {
    return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}
int main() {
    cin >> n;
    // memset(f, 0x3f, sizeof(f));
    for (int i=0;i<=(1 << (n+1));i++) for (int j=0;j<=n;j++) f[i][j] = inf;
    for (int i=1;i<=n;i++) {
        cin >> xy[i].first >> xy[i].second;
    }
    xy[0] = {0, 0};
    for (int i=0;i<=n;i++) {
        for (int j=0;j<=n;j++) {
            if (i == j) dis[i][j] = 0;
            else dis[i][j] = caldis(xy[i], xy[j]);
        }
    }
    f[1][0] = 0;
    for (int S = 1; S < (1 << (n+1));S++) {
        for (int j=0;j<=n;j++) {
            if (S>>j & 1) {
                for (int k=0;k<=n;k++) {
                    if (S^(1<<j) >> k & 1) {
                        f[S][j] = min(f[S][j], f[S^(1<<j)][k] + dis[j][k]);
                    }
                }
            }
        }
    }
    double ans = 1e9;
    for (int i=1;i<=n;i++) ans = min(ans, f[(1<<(n+1)) - 1][i]);
    cout << fixed << setprecision(2) << ans;
}