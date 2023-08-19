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

int n, m, s;
struct Eage
{
    int to, next = -1;
} e[1000005];
int fa[500005][25];
int cnt; int head[500005];
int d[500005];
void addE (int u, int v) {
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt++;
}
void init_fa_deep (int x, int father) {
    d[x] = d[father] + 1;
    fa[x][0] = father;
    for (int i=1;(1<<i) < d[x];i++) { //
        fa[x][i] = fa[fa[x][i-1]][i-1];
    }
    for (int i=head[x];i != -1;i=e[i].next) if (e[i].to != father) {
        init_fa_deep (e[i].to, x);
    }
}
int jump (int x, int y) {
    if (d[x] < d[y]) swap (x, y);
    for (int i=19;i>=0;i--) {
        if (d[x] == d[y]) break;
        if (d[fa[x][i]] >= d[y]) x = fa[x][i];
    }
    if (x == y) return x;
    for (int i=19;i>=0;i--) {
        if (fa[x][i] != fa[y][i]) {
            x = fa[x][i]; y = fa[y][i];
        }
    }
    return fa[x][0];
}
int main() {
    cin >> n >> m >> s;
    memset (head, -1, sizeof (head));
    for (int i=0;i<n-1;i++) {
        int u, v; cin >> u >> v;
        addE (u, v); addE (v, u);
    }
    init_fa_deep (s, 0);
    while (m--) {
        int x, y; cin >> x >> y;
        cout << jump(x, y) << endl;
    }
}