// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int dis[205][205][205];
bool e[205][205];
int n, m, k;
void add (int x, int y) {
    if (x == 1 && y == 1) {dis[x][y][0] = 1; return;}
    for (int i=0;i<=200;i++) {
        dis[x][y][i] += dis[x-1][y][i] + dis[x][y-1][i];
        if (dis[x][y][i] >= 10) dis[x][y][i] -= 10, dis[x][y][i+1]++;
    }
}
int main() {
    cin >> n >> m >> k;
    for (int i=0;i<k;i++) {
        int x, y; cin >> x >> y; e[x][y] = 1;
    }
    // dis[1][1][0] = 1;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) if (!e[i][j]) {
            add(i, j);
        }
    }
    bool flag = false;
    for (int i=200;i>=0;i--) {
        if (dis[n][m][i]) flag = true;
        if (flag) cout << dis[n][m][i];
    }
    cout << endl;
}