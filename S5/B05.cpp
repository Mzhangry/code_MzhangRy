// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int k, n, ha, la, hb, lb;
char e[105][105];
bool vis[105][105];
int d1[4] = {1, 0, -1, 0},
    d2[4] = {0, 1, 0, -1};

bool dfs (int a, int b) {
    if (a == hb && b == lb) return true;
    vis[a][b] = true;
    bool flag = false;
    for (int i=0;i<4;i++) {
        int aa = a + d1[i], bb = b + d2[i];
        if (aa >= 0 && aa < n && bb >= 0 && bb < n && e[aa][bb] == '.' && !vis[aa][bb] && dfs(aa, bb)) return true;
    }
    return false;
}
int main() {
    cin >> k;
    while (k--) {
        cin >> n;
        memset(vis, 0, sizeof(vis));
        memset(e, 0, sizeof(e));
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                cin >> e[i][j];
            }
        }
        cin >> ha >> la >> hb >> lb;
        if (e[ha][la] == '#') {
            cout << "NO" << endl;
            continue;
        }
        if (dfs(ha, la)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}