// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define double long double
struct Tri {
    int v; double b, c;
};
int n, m;
vector< vector<Tri> > e;
const double inf = 1e15+10;
const double mi = 1e-11;
vector<int> deg;
bool check (double num) {
    queue<int> q; for (int i=1;i<=n;i++) if (!deg[i]) q.push(i);
    vector<double> f(n+1, -inf);
    vector<int> cnt(n+1);
    f[1] = 0;
    while (!q.empty()) {
        int d = q.front(); q.pop();
        for (auto p : e[d]) {
            f[p.v] = max(f[p.v], f[d] + (p.b - num*p.c));
            if (++cnt[p.v] == deg[p.v]) q.push(p.v);
        }
    }
    if (f[n] >= 0) return true;
    return false;
}
int main() {
    cin >> n >> m;
    e.resize(n+1); deg.resize(n+1); // ind.resize(n+1);
    for (int i=0;i<m;i++) {
        int u, v; double b, c; cin >> u >> v >> b >> c;
        e[u].push_back({v, b, c});
        deg[v]++;
    }
    
    
    double l = 0, r = inf, mid;
    while (r - l >= mi) {
        mid = (l+r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << fixed << setprecision(11) << l << endl;
}