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
const int inf = 1e9;
typedef long long ll;
typedef pair<int, int> P;

int n;
int ea[55][55], eb[55][55];
int da[55][55], db[55][55];
queue<P> q;
int dx[4] = {1, 0, -1, 0},
    dy[4] = {0, 1, 0, -1};
bool vis[55][55];
int mxa1 = 0, mxb1 = 0;
int mxa = 0, mxb = 0;

bool inbound (int x, int y) {
    return x>=1 && x<=n && y>=1 && y<=n;
}

void bfs (int e[][55], int ans[][55], int xa, int ya, int xb, int yb) {
    for (int stx=xa;stx<=xb;stx++) {
        for (int sty=ya;sty<=yb;sty++) {
            if (!e[stx][sty]) continue;
            memset (vis, 0, sizeof(vis));
            q.push({stx, sty});
            while (!q.empty()) {
                P d = q.front(); q.pop();
                for (int i=0;i<4;i++) {
                    int nx = d.first + dx[i], ny = d.second + dy[i];
                    if (inbound(nx, ny) && e[nx][ny] == 1 && !vis[nx][ny]) {
                        vis[nx][ny] = true;
                        ans[stx][sty]++;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) cin >> ea[i][j];
    for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) cin >> eb[i][j];
    bfs (ea, da, 1, 1, n, n);
    bfs (eb, db, 1, 1, n, n);
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (i == 1 || i == n || j == 1 || j == n) {
                if (ea[i][j] == 1 && db[i][j] > mxa1) mxa1 = db[i][j];
                if (eb[i][j] == 1 && da[i][j] > mxb1) mxb1 = da[i][j];
            }
            if (ea[i][j] == 1 && db[i][j] > mxa) mxa = db[i][j];
            if (eb[i][j] == 1 && da[i][j] > mxb) mxb = da[i][j];
        }
    }
    cout << max (mxa1+mxb1, max(mxa, mxb)) << endl;
}