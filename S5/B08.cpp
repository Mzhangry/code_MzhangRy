// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int m, n;
bool w[55][55], e[55][55], north[55][55], s[55][55], vis[55][55];
int p[55][55];
int mx = 0, ans = 0;
int dx[4] = {0, 1, 0, -1},
    dy[4] = {1, 0, -1, 0};

int dfs(int a, int b) {
    vis[a][b] = true;
    int sz = 1;
    for (int i=0;i<4;i++) {
        int aa = a+dx[i], bb = b+dy[i];
        if (aa < 0 || bb < 0 || aa >= m || bb >=n) continue;
        if (i == 0 && !e[a][b] && !vis[aa][bb]) sz += dfs(aa, bb); // 向右
        else if (i == 1 && !s[a][b] && !vis[aa][bb]) sz += dfs(aa, bb);
        else if (i == 2 && !w[a][b] && !vis[aa][bb]) sz += dfs(aa, bb);
        else if (i == 3 && !north[a][b] && !vis[aa][bb]) sz += dfs(aa, bb);
    }
    return sz;
}

int main() {
    cin >> m >> n;
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            cin >> p[i][j];
        }
    }
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) { // 墙的有无判断
            if (p[i][j] >= 8) {
                s[i][j] = true;
                p[i][j] -= 8;
            }
            if (p[i][j] >= 4) {
                e[i][j] = true;
                p[i][j] -= 4;
            }
            if (p[i][j] >= 2) {
                north[i][j] = true;
                p[i][j] -= 2;
            }
            if (p[i][j] == 1) w[i][j] = true;
        }
    }

    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            if (!vis[i][j]) {
                mx = max(mx, dfs(i, j));
                ans++;
            }
        }
    }
    cout << ans << endl << mx << endl;
}