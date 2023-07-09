// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int w, h;
bool vis[25][25];
char e[25][25];
int as, bs;
int dx[4] = {0, 1, 0, -1},
    dy[4] = {1, 0, -1, 0};

int dfs(int a, int b) {
    int sum = 1;
    vis[a][b] = true;
    for (int i=0;i<4;i++) {
        int aa = a+dx[i], bb = b+dy[i];
        if (aa >= 0 && aa < h && bb >=0 && bb < w && !vis[aa][bb] && e[aa][bb] == '.') sum += dfs(aa, bb);
    }
    return sum;
}

int main() {
    while (cin >> w >> h) {
        if (w == 0 && h == 0) return 0;
        memset (vis, 0, sizeof(vis));
        memset (e, 0, sizeof(e));
        for (int i=0;i<h;i++) {
            for (int j=0;j<w;j++) {
                cin >> e[i][j];
                if (e[i][j] == '@') {
                    as = i;
                    bs = j;
                }
            }
        }

        cout << dfs(as, bs) << endl;
    }
}