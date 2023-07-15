// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> P;

int n, m, k;
char e[1005][1005];
queue<P> que;
int pos[1005][1005][25];
int dx[4] = {0, 1, 0, -1},
    dy[4] = {1, 0, -1, 0};
int main() {
    cin >> n >> m >> k;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cin >> e[i][j];
        }
    }
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) for (int q=0;q<2*k;q++) pos[i][j][q] = 1e9;
    pos[1][1][0] = 0;
    que.push(make_pair(1, 1));
    P ans(n, m);
    while (!que.empty()) {
        P d = que.front(); que.pop();
        if (d == ans) break;
        for (int i=0;i<4;i++) {
            int x = d.first + dx[i], y = d.second + dy[i];
            if (! (x >= 1 && x <= n && y >= 1 && y <= m)) continue;
            for (int q=0;q<2*k;q++) {
                if (pos[d.first][d.second][q] != 1e9 && pos[x][y][(q+1)%(2*k)] > pos[d.first][d.second][q] + 1 && ((q+1) % (2*k) < k ? e[x][y] == 'A' : e[x][y] == 'B')) {
                    pos[x][y][(q+1)%(2*k)] = pos[d.first][d.second][q] + 1;
                    que.push (make_pair(x, y));
                }
            }
        }
    }
    int anss = 1e9;
    for (int i=0;i<2*k;i++) {
        anss = min(anss, pos[n][m][i]);
    }
    if (anss == 1e9) cout << -1;
    else cout << anss;
}