// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

char e[105][105];
bool vis[105][105];
int ha, la, hb, lb, n;
int dx[4] = {0, 1, 0, -1},
    dy[4] = {1, 0, -1, 0};

bool dfs(int a, int b) {
    vis[a][b] = true;
    if (a == hb && b == lb) return true;
    for (int i=0;i<4;i++) {
        int aa = a+dx[i], bb = b+dy[i];
        if (aa >= 0 && aa < n && bb >=0 && bb < n && e[aa][bb] == '.' && !vis[aa][bb] && dfs(aa, bb)) return true;
    }
    return false;
}

int main() {
    int k;
    cin >> k;
    while (k--) {
        memset (e, 0, sizeof(e));
        memset (vis, 0, sizeof(vis));
        cin >> n;
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                cin >> e[i][j];
            }
        }
        cin >> ha >> la >> hb >> lb;
        if (e[ha][la] == '#' || e[hb][lb] == '#') {
            cout << "NO" << endl;
            continue;
        }
        if (dfs(ha, la)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}