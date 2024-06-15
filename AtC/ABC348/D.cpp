// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;

int h, w, n;
char e[205][205];
int dis[305][305];
const int inf = 1e9 + 10;
int r[305], c[305], energy[305];
int dx[4] = {0, 1, 0, -1},
    dy[4] = {1, 0, -1, 0};
int efood[205][205];

bool inbound(int x, int y) {
    if (x >= 1 && y >= 1 && x <= h && y <= w && e[x][y] != '#') return true;
    else return false;
}
void bfs (int st) {
    int tdis[205][205];
    for (int i=1;i<=200;i++) for (int j=1;j<=200;j++) tdis[i][j] = inf;
    queue<p> q; q.push({r[st], c[st]}); tdis[r[st]][c[st]] = 0;
    
    while (!q.empty()) {
        p d = q.front(); q.pop();
        for (int t=0;t<4;t++) {
            int x = d.first + dx[t], y = d.second + dy[t];
            if (inbound(x, y) && tdis[x][y] > tdis[d.first][d.second] + 1) {
                tdis[x][y] = tdis[d.first][d.second] + 1;
                if (efood[x][y]) dis[st][efood[x][y]] = tdis[x][y];
                q.push({x, y});
            }
        }
    }
}
int stx, sty, edx, edy;
int spare;
vector<bool> vis(305);
bool dfs (int now) {
    if (spare >= dis[now][301]) return true;
    int tspare = spare;
    for (int i=1;i<=n;i++) {
        if ((!vis[i]) && (spare >= dis[now][i])) {
            vis[i] = true; spare = energy[i];
            if (dfs(i)) return true;
            vis[i] = false; spare = tspare;
        }
    }
    return false;
}
int main() {
    cin >> h >> w;
    for (int i=1;i<=h;i++) for (int j=1;j<=w;j++) {
        cin >> e[i][j];
        if (e[i][j] == 'S') stx = i, sty = j;
        else if (e[i][j] == 'T') edx = i, edy = j;
    }
    for (int i=1;i<=301;i++) for (int j=1;j<=301;j++) dis[i][j] = inf;
    cin >> n;
    for (int i=1;i<=n;i++) {
        cin >> r[i] >> c[i] >> energy[i];
        efood[r[i]][c[i]] = i;
    }
    efood[edx][edy] = 301;
    for (int i=1;i<=n;i++) bfs(i);

    if (!efood[stx][sty]) {
        cout << "No" << endl;
        return 0;
    }

    spare = energy[efood[stx][sty]];
    vis[efood[stx][sty]] = true;
    if (dfs(efood[stx][sty])) cout << "Yes" << endl;
    else cout << "No" << endl;

}