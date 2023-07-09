// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int n, m;
char e[105][105];
bool vis[105][105];
int dx[8] = {0, 1, 0, -1, -1, -1, 1, 1},
    dy[8] = {1, 0, -1, 0, -1, 1, -1, 1};

void dfs (int a, int b) {
    vis[a][b] = true;
    for (int i=0;i<8;i++) {
        int aa = a+dx[i], bb = b+dy[i];
        if (aa >= 0 && aa < n && bb >= 0 && bb < m && e[aa][bb] == 'W' && !vis[aa][bb]) dfs(aa, bb);
    }
}

int main() {
    cin >> n >> m;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> e[i][j];
        }
    }
    int ans = 0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (e[i][j] == 'W' && !vis[i][j]) {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans;
}