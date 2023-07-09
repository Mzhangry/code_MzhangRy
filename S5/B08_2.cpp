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
int a[55][55];
bool vis[55][55];
int ans = 0, mx = 0;
int dx[4] = {0, -1, 0, 1},
    dy[4] = {-1, 0, 1, 0};

int dfs (int x, int y) { // dfs(x, y)返回 x,y 所在房间大小 （已经访问过的坐标不会被再计算大小）
    vis[x][y] = true;
    int cnt = 1;
    for (int i=0;i<4;i++) if (! (a[x][y] >> i & 1)) { // 若if内为true 则表示第i位为0 对应位没有墙 往该方向dfs
        int xx = x + dx[i], yy = y + dy[i]; // 不判断xx, yy是否inbound了 因为城堡四周都有墙
        if (!vis[xx][yy]) cnt += dfs(xx, yy);
    }
    return cnt;
}
int main() {
    cin >> m >> n;
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            cin >> a[i][j];
        }
    }
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            if (!vis[i][j]) {
                mx = max(mx, dfs(i, j)); // 记录房间最大值
                ans ++;
            }
        }
    }
    cout << ans << endl << mx << endl;
}