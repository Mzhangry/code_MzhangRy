// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int h, w;
char e[25][25];
bool vis[25][25];
int dx[4] = {0, 1, 0, -1}, 
    dy[4] = {1, 0, -1, 0};

int dfs (int a, int b) {
    int cur = 1;
    vis[a][b] = true;

    for (int i=0;i<4;i++) {
        int aa = a + dx[i], bb = b + dy[i];
        if (aa >= 0 && aa < h && bb >= 0 && bb < w && e[aa][bb] == '.' && !vis[aa][bb]) cur += dfs(aa, bb);
    }
    return cur;
}
int main() {
    while (cin >> w >> h) {
        if (w == 0) return 0;
        memset (vis, 0, sizeof(vis));
        for (int i=0;i<h;i++) cin >> e[i];
        for (int i=0;i<h;i++) {
            for (int j=0;j<w;j++) {
                if (e[i][j] == '@') cout << dfs (i, j) << endl;
            }
        }
    }
}