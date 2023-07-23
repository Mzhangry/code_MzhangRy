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

int n;
int a[55][55], b[55][55][4], e[205][205];
int ans = 0;
bool vis[205][205];
int dx[4] = {0, 1, 0, -1},
    dy[4] = {1, 0, -1, 0};

int dfs (int x, int y) {
    vis[x][y] = true;
    int cnt = 1;
    for (int i=0;i<4;i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (e[xx][yy] && !vis[xx][yy]) cnt += dfs(xx, yy);
    }
    return cnt;
}

void solve (int stx, int sty, int edx, int edy) {
    for (int i=stx; i<=edx; i++) { // 枚举起始
        for (int j=sty; j<=edy; j++) {
            for (int k=0;k<4;k++) {
                for (int p=1;p<=n;p++) { // coverb
                    for (int t=1;t<=n;t++) {
                        e[i+p-1][j+t-1] = b[p][t][k];
                    }
                }
                memset (vis, 0, sizeof (vis));
                for (int p=50;p<=150;p++) { // dfs
                    for (int t=50;t<=150;t++) {
                        if (e[p][t] && !vis[p][t]) ans = max (ans, dfs(p, t));
                    }
                }
                for (int p=1;p<=n;p++) { // cover0
                    for (int t=1;t<=n;t++) {
                        e[i+p-1][j+t-1] = 0;
                    }
                }
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) cin >> a[i][j];
    for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) cin >> b[i][j][0];
    for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) {
        b[i][j][1] = b[j][n-i+1][0];
        b[i][j][2] = b[n-i+1][n-j+1][0];
        b[i][j][3] = b[n-j+1][i][0];
    }
    for (int i=100;i<100+n;i++) for (int j=100;j<100+n;j++) e[i][j] = a[i-100+1][j-100+1];
    solve (100-n, 100-n+1, 100-n, 100+n-1);
    solve (100-n+1, 100-n, 100+n-1, 100-n);
    solve (100+n, 100-n+1, 100+n, 100+n-1);
    solve (100-n+1, 100+n, 100+n-1, 100+n);
    cout << ans << endl;
    return 0;
}