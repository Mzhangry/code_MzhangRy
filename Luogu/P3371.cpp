// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e4 + 10;
const int inf = 2147483647;
int n, m, st;
struct Edge
{
    int to, v;
};
vector<Edge> e[maxn];
bool ok[maxn]; int dis[maxn];
struct Node
{
    int id, dis;
    bool operator < (const Node d) const {
        return dis > d.dis;
    }
};
priority_queue<Node> q;

void dijkstra () {
    for (int i=1;i<=n;i++) dis[i] = inf;
    dis[st] = 0;
    q.push({st, 0});
    while (!q.empty()) {
        auto d = q.top(); q.pop();
        if (ok[d.id]) continue;
        ok[d.id] = true;
        for (auto v : e[d.id]) {
            if (ok[v.to]) continue;
            if (d.dis + v.v < dis[v.to]) {
                dis[v.to] = d.dis + v.v;
                q.push({v.to, dis[v.to]});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> st;
    for (int i=0;i<m;i++) {
        int u, v, d; cin >> u >> v >> d;
        e[u].push_back({v, d});
    }
    dijkstra();
    for (int i=1;i<=n;i++) {
        cout << dis[i] << ' ';
    }
    cout << endl;
}