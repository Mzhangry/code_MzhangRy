// MzhangRy - 张容钰
// 提前处理所有 B 可达的 A集中最大的前三个
//        所有 C 可达的 D集中最大的前三个 --- 其实A集和D集是一样的 处理一次即可
// 对于所有的 B （枚举n），枚举可达的 C
// ABCD不能重复！！
// -> 选A A不能为C 如果为C 就选B可到的「A」的第二个
// -> 选D D不能为A、B 如果为B 就从第二个开始选
//                   如果为A 选A的下一个、本C or 本A、C的下一个
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int n, m, k;
ll val[2505];
ll ans = 0;
vector<int> ok[2505], e[2505];
void bfs (int st) {
    queue<P> q; q.push({st, 0});
    vector<bool> vis(n+1); vis[st] = 1;
    while (!q.empty()) {
        P d = q.front(); q.pop();
        if (d.second == k) return;
        for (int v : e[d.first]) if (!vis[v]) {
            vis[v] = true;
            q.push({v, d.second + 1});
            ok[st].push_back(v);
        }
    }
}
unordered_set<int> AD;
vector< vector<int> > gotoAD;
ll findAns (int b, int c) {
    // unordered_set<int> s; s.insert(c); s.insert(b);
    ll sumad = 0;
    for (int a : gotoAD[b]) {
        for (int d : gotoAD[c]) if (a != b && a != c && a != d && b != d) {
            sumad = max(sumad, val[a] + val[d]);
        }
    }
    if (sumad == 0) return 0;
    return sumad + val[b] + val[c];
}
int main() {
    // freopen("P8817.in", "r", stdin);
    // freopen("P8817.out", "w", stdout);
    cin >> n >> m >> k; k++;
    for (int i=2;i<=n;i++) cin >> val[i];
    while (m--) {
        int u, v; cin >> u >> v;
        e[u].push_back(v); e[v].push_back(u);
    }
    // 求全源最短路
    for (int i=1;i<=n;i++) bfs(i);

    // 处理每个点可达的A/D的前三大
    gotoAD.resize(n+2);
    for (int d : ok[1]) AD.insert(d);
    for (int d : AD) {
        for (int v : ok[d]) {
            gotoAD[v].push_back(d);
            sort (gotoAD[v].begin(), gotoAD[v].end(), [=] (int a, int b) {return val[a] > val[b];});
            if (gotoAD[v].size() > 3) gotoAD[v].pop_back();
        }
    }

    for (int b=2;b<=n;b++) { // B
        for (int c : ok[b]) if (c != 1) { // C
            ans = max(ans, findAns(b, c));
        }
    }

    cout << ans << endl;
}