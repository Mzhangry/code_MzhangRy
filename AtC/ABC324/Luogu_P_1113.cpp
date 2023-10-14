// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector< vector<int> > e;
int main() {
    cin >> n;
    e.resize(n+1);
    vector<int> len(n+1), dis(n+1), deg(n+1);
    for (int i=1;i<=n;i++) { // input
        int _; cin >> _; // 编号 无用
        cin >> len[i];
        int u = 0;
        while (1) {
            deg[i] ++;
            cin >> u; e[u].push_back(i);
            if (u == 0) break;
        }
    }

    queue<int> q; q.push(0);
    while (!q.empty()) {
        int d = q.front(); q.pop();
        for (int v : e[d]) {
            dis[v] = max(dis[v], dis[d] + len[v]);
            if (--deg[v] == 0) q.push(v);
        }
    }
    int ans = 0;
    for (int i=1;i<=n;i++) ans = max(ans, dis[i]);
    cout << ans << endl;
}