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

int n, m;
char e[205][205];
bool vis[205][205];
bool st[205][205];
int ans = 1;
void dfs (int x, int y, int d) {
    int cnt = 0; st[x][y] = true;
    if (d == 1) {
        x++;
        while (e[x][y] != '#') {
            if (!vis[x][y]) cnt++;
            vis[x][y] = true;
            x++;
        }
        x--;
    } else if (d == 2) {
        y++;
        while (e[x][y] != '#') {
            if (!vis[x][y]) cnt++;
            vis[x][y] = true;
            y++;
        }
        y--;
    } else if (d == 3) {
        x--;
        while (e[x][y] != '#') {
            if (!vis[x][y]) cnt++;
            vis[x][y] = true;
            x--;
        }
        x++;
    } else if (d == 4) {
        y--;
        while (e[x][y] != '#') {
            if (!vis[x][y]) cnt++;
            vis[x][y] = true;
            y--;
        }
        y++;
    }
    ans += cnt;
    if (!st[x][y]) {
        if (d == 1) {
            if (e[x][y+1] != '#') dfs(x, y, 2);
            if (e[x][y-1] != '#') dfs(x, y, 4);
        } else if (d == 2) {
            if (e[x+1][y] != '#') dfs(x, y, 1);
            if (e[x-1][y] != '#') dfs(x, y, 3);
        } else if (d == 3) {
            if (e[x][y+1] != '#') dfs(x, y, 2);
            if (e[x][y-1] != '#') dfs(x, y, 4);
        } else if (d == 4) {
            if (e[x+1][y] != '#') dfs(x, y, 1);
            if (e[x-1][y] != '#') dfs(x, y, 3);
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cin >> e[i][j];
        }
    }
    vis[2][2] = true;
    dfs (2, 2, 1);
    dfs (2, 2, 2);
    dfs (2, 2, 3);
    dfs (2, 2, 4);
    cout << ans << endl;
}