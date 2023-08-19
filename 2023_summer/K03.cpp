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

int n, k;
char e[10][10];
ll ans = 0;
bool vis[10][10];
int cnt = 0;
bool inbound (int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}
int dx[4] = {0, 1, 0, -1},
    dy[4] = {1, 0, -1, 0};

void dfs (int x, int y) {
    if (e[x][y] == '#') return;
    cnt++;
    if (cnt == k) {
        ans ++; cnt--; return;
    }

    for (int i=0;i<4;i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (inbound (xx, yy) && !vis[xx][yy]) dfs (xx, yy);
    }
    cnt--;
    return;
}

int main() {
    cin >> n >> k;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin >> e[i][j];
        }
    }    
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            vis[i][j] = true;
            dfs (i, j);
        }
    }
    cout << ans << endl;
}