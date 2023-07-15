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
struct P
{
    int first, second, dis;
};


int n, m, k;
char e[1005][1005];
queue<P> que;

int dx[4] = {0, 1, 0, -1},
    dy[4] = {1, 0, -1, 0};
int main() {
    cin >> n >> m >> k;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cin >> e[i][j];
        }
    }
    // for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) pos[i][j] = 1e9;
    que.push({1, 1, 0});
    while (!que.empty()) {
        P d = que.front(); que.pop();
        if (d.first == n && d.second == m) {
            cout << d.dis;
            return 0;
        }
        for (int i=0;i<4;i++) {
            int x = d.first + dx[i], y = d.second + dy[i];
            if (x >= 1 && x <= n && y >= 1 && y <= m && d.dis + && ((pos[d.first][d.second]+1) % (2*k) < k ? e[x][y] == 'A' : e[x][y] == 'B')) {
                pos[x][y] = pos[d.first][d.second] + 1;
                que.push (make_pair(x, y));
            }
        }
    }
    cout << -1;
}