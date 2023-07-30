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

int n, m;
int w[100005];
vector<int> e[100005];
int dis[3][100005]; // 0a 1b 2c
const int inf = 1e9;
int a, b, c;
queue<int> q;
ll sum[100005];
void bfs (int st, int d) {
    q.push(st);
    for (int i=0;i<=n;i++) dis[d][i] = inf;
    dis[d][st] = 0;
    while (!q.empty()) {
        int dd = q.front(); q.pop();
        for (int v : e[dd]) {
            if (dis[d][v] > dis[d][dd] + 1) {
                dis[d][v] = dis[d][dd] + 1;
                q.push(v);
            }
        }
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i=0;i<=n;i++) e[i].clear();
        cin >> a >> b >> c;
        for (int i=0;i<m;i++) cin >> w[i];
        for (int i=0;i<m;i++) {
            int u, v; cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        bfs (a, 0); bfs (b, 1); bfs (c, 2);
        
        sort (w, w+m);
        for (int i=0;i<m;i++) sum[i+1] = sum[i] + w[i];
        ll ans = 1e18;
        for (int i=1;i<=n;i++) {
            if (dis[0][i] + dis[1][i] + dis[2][i] <= m) {
                ans = min(ans, sum[dis[0][i] + dis[1][i] + dis[2][i]] + sum[dis[1][i]]);
            }
        }
        cout << ans << endl;
    }
}