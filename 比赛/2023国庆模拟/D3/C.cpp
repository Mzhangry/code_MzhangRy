#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, w, d;
const int inf = 1e9;
vector<int> er[2005]; int bus[2005];
bool tim[2005];
int dis[2005]; bool ok[2005];
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
    memset (ok, 0, sizeof(ok));
    dis[1] = 0;
    q.push({1, 0});
    while (!q.empty()) {
        auto d = q.top(); q.pop();
        if (ok[d.id]) continue;
        ok[d.id] = true;
        for (int i : er[d.id]) {
            if (ok[i]) continue;
            if (d.dis + 1 < dis[i]) {
                dis[i] = d.dis + 1;
                q.push({i, dis[i]});
            }
        }
        int i = bus[d.id]; 
            if (ok[i]) continue; if (tim[i] - d.dis < 0) continue;
            if (d.dis + tim[i] - d.dis + 1 < dis[i]) {
                dis[i] = d.dis + tim[i] - d.dis + 1;
                q.push({i, dis[i]});
            }
        
    }
}

int main() {
    cin >> n >> w >> d;
    for (int i=0;i<w;i++) {
        int a, b; cin >> a >> b; er[a].push_back(b);
    }
    vector<int> xl(n+1); for (int i=1;i<=n;i++) {cin >> xl[i]; tim[xl[i]] = i;}
    for (int i=2;i<=n;i++) bus[xl[i-1]] = xl[i];
    while (d--) {
        int a, b; cin >> a >> b;
        swap (bus[xl[a-1]], bus[xl[b-1]]); swap (bus[xl[a]], bus[xl[b]]);
        swap (xl[a], xl[b]); swap (tim[xl[a]], tim[xl[b]]);
        dijkstra();
        cout << dis[n] << endl;
    }
}
