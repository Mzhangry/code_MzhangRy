// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int e[4][4], vis[4][4];
struct Point {
    int x = -1, y = -1; int d;
};
int cnt = 0, dis = 0;
bool flag = false;
bool check (int x, int y) {
    vector<int> a;
    for (int j=1;j<=3;j++) if (j != y && vis[x][j]) a.push_back(e[x][j]);
    if (a.size() == 2 && a[0] == a[1]) return true; a.clear();
    for (int i=1;i<=3;i++) if (i != x && vis[i][y]) a.push_back(e[i][y]);
    if (a.size() == 2 && a[0] == a[1]) return true; a.clear();
    if (x == y) {
        for (int i=1;i<=3;i++) if (vis[i][i] && x != i) a.push_back(e[i][i]);
        if (a.size() == 2 && a[0] == a[1]) return true; a.clear();
    }
    if (x + y == 4) {
        for (int i=1;i<=3;i++) if (vis[i][4-i] && x != i) a.push_back(e[i][4-i]);
        if (a.size() == 2 && a[0] == a[1]) return true; a.clear();
    }
    return false;
}
void dfs (int x, int y, int num, Point la1, Point la2) {
    vis[x][y] = true; bool edit = false;
    if (!flag && check(x, y)) {
        flag = true; edit = true;
    }
    if (num == 9) {
        vis[x][y] = false;
        if (flag) dis++; cnt++;
        if (edit) flag = false;
        return;
    }
    for (int i=1;i<=3;i++) for (int j=1;j<=3;j++) if (!vis[i][j]) dfs (i, j, num+1, {x, y, e[x][y]}, la1);
    vis[x][y] = false;
    if (edit) flag = false;
}
int main() {
    for (int i=1;i<=3;i++) for (int j=1;j<=3;j++) cin >> e[i][j];
    for (int i=1;i<=3;i++) for (int j=1;j<=3;j++) dfs (i, j, 1, {-1, -1, -1}, {-1, -1, -1});
    cout << fixed << setprecision(10) << 1.0 - 1.0*dis / cnt << endl;
}