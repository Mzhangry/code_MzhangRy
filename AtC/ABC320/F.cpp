// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, h;
const int inf = 1e9;
struct Node {
    int x=0, p=0, f=0;
};
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> h;
    vector<Node> e(n+1);
    for (int i=1;i<=n;i++) cin >> e[i].x;
    for (int i=1;i<=n-1;i++) {
        cin >> e[i].p >> e[i].f;
    }
    vector< vector< vector<int> > > f(n+1, vector< vector<int> > (h+1, vector<int> (h+1, inf)));
    for (int i=0;i<=h;i++) f[0][h][i] = 0;
    for (int i=1;i<=n;i++) {
        int d = e[i].x - e[i-1].x;
        // 本轮不加
        for (int j=d;j<=h;j++) { // 上一轮有j油
            for (int k=d;k<=h;k++) { // 本轮有k油
                if (f[i-1][j][k - d] != inf) {
                    f[i][j - d][k] = min(f[i][j-d][k], f[i-1][j][k-d]);
                }
            }
        }
        // 本轮加
        vector< vector<int> > now1(h+1, vector<int> (h+1, inf)), now2(h+1, vector<int> (h+1, inf));
        for (int j=0;j<=h;j++) {
            for (int k=0;k<=h;k++) {
                now1[min(h, j+e[i].f)][k] = min(now1[min(h, j+e[i].f)][k], f[i][j][k] + e[i].p);
                if (k == h) for (int p=0;p<=e[i].f;p++) {
                    now2[j][k-p] = min(now2[j][k-p], f[i][j][k] + e[i].p);
                } else if (k >= e[i].f) {
                    now2[j][k-e[i].f] = min(now2[j][k-e[i].f], f[i][j][k] + e[i].p);
                }
            }
        }
        for (int j=0;j<=h;j++) for (int k=0;k<=h;k++) f[i][j][k] = min(f[i][j][k], min(now1[j][k], now2[j][k]));
    }
    int ans = inf;
    for (int i=0;i<=h;i++) ans = min(ans, f[n][i][i]);
    if (ans == inf) cout << -1 << endl;
    else cout << ans << endl;
}