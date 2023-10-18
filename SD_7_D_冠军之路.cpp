// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
char e[105][105];
int tot;
map<char, int> dx, dy;

int stx, sty, edx, edy;

bool inbound (int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m && (e[x][y] == '.' || e[x][y] == 'I' || e[x][y] == 'O');
}
const int inf = 1e9;
struct Node
{
    int x, y;
};

int tx[4] = {0, 1, 0, -1},
    ty[4] = {1, 0, -1, 0};
struct Tri {
    int dis, x, y;
};
vector<Node> att[11];
Tri dis[11][105][105];
void init_dis() {
    for (int i=1;i<=10;i++) {
        for (Node st : att[i]) {
            queue<Node> q;
            dis[i][st.x][st.y] = {0, st.x, st.y}; q.push({st.x, st.y});
            while (!q.empty()) {
                Node u = q.front(); q.pop();
                for (int t=0;t<4;t++) {
                    int nx = u.x + tx[t], ny = u.y + ty[t];
                    if (inbound(nx, ny) && dis[i][nx][ny].dis > dis[i][u.x][u.y].dis + 1) {
                        dis[i][nx][ny] = {dis[i][u.x][u.y].dis + 1, dis[i][u.x][u.y].x, dis[i][u.x][u.y].y};
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
}
Tri bfsdis(int x, int y, int d) {
    return dis[d][x][y];
}
int ans = 1e9;
bool ok[10];
void dfs (int num, int stx, int sty, int now) {
    if (num == tot + 1) {
        int d = bfsdis (stx, sty, 10).dis;
        if (d < inf) ans = min(ans, d + now);
        return;
    }

    for (int i=1;i<=tot;i++) if (!ok[i]) {
        Tri d = bfsdis (stx, sty, i);
        ok[i] = true;
        if (d.dis < inf) dfs (num + 1, d.x, d.y, now + d.dis);
        ok[i] = false;
    }
}
void init() {
    dx['a'] = dx['d'] = 0;
    dy['w'] = dy['s'] = 0;
    dx['s'] = dy['d'] = 1;
    dx['w'] = dy['a'] = -1;
    tot = 0; ans = 1e9;
    for (int i=0;i<=10;i++) for (int j=1;j<=n;j++) for (int k=1;k<=m;k++) dis[i][j][k].dis = inf;
    for (int i=0;i<=10;i++) att[i].clear();
}
int main() {
    int t; cin >> t; while (t--) {
        cin >> n >> m;
        init();
        for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cin >> e[i][j];
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                if (e[i][j] == 'I') stx = i, sty = j;
                else if (e[i][j] == 'O') edx = i, edy = j;
                else if (e[i][j] >= 'a' && e[i][j] < 'z') {
                    tot++;
                    for (int x = i+dx[e[i][j]], y = j+dy[e[i][j]]; inbound(x, y); x += dx[e[i][j]], y += dy[e[i][j]]) {
                        att[tot].push_back({x, y});
                    }
                }
            }
        }
        att[10].push_back({edx, edy});
        init_dis();
        dfs(1, stx, sty, 0);
        cout << (ans == inf ? -1 : ans) << endl;
    }
}