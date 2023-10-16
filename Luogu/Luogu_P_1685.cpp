// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 10000;
int n, m, st, ed, t;
struct Node
{
    int to, tim;
};
vector< vector<Node> > e;
void moplus (int &a, int b) {a = (a+b) % mod;}
int main() {
    cin >> n >> m >> st >> ed >> t;
    e.resize(n+1);
    vector<int> deg(n+1);
    while (m--) {
        int u, v, t; cin >> u >> v >> t;
        e[u].push_back({v, t});
        deg[v] ++;
    }
    vector<int> sum(n+1), cnt(n+1); cnt[st] = 1;
    queue<int> q; q.push(st);
    while (!q.empty()) {
        int d = q.front(); q.pop();
        for (Node v : e[d]) {
            deg[v.to]--; moplus(sum[v.to], sum[d] + cnt[d] * v.tim);
            moplus(cnt[v.to], cnt[d]);
            if (deg[v.to] == 0) q.push(v.to);
        }
    }
    cout << (sum[ed] + (cnt[ed] - 1) * t) % mod << endl;
}