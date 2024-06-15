// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n; vector<int> x;
vector< vector<int> > e;
// vector<int> deg;
const int mod = 998244353;
unordered_map<int, int> f(int d) {
    unordered_map<int, int> m; m[x[d]] = 1;
    for (int v : e[d]) {
        auto t = f(v);
        unordered_map<int, int> m1;
        for (auto p : m) for (auto q : t) m1[p.first ^ q.first] = (m1[p.first ^ q.first] + 1ll * p.second * q.second) % mod, m1[p.first * q.first] = (m1[p.first * q.first] + 1ll * p.second * q.second) % mod;
        m = m1;
    }
    return m;
}


int main() {
    // freopen ("xor4.in", "r", stdin);
    cin >> n;
    x.resize(n+1); e.resize(n+1); // deg.resize(n+1);
    for (int i=1;i<=n;i++) cin >> x[i];
    for (int i=2;i<=n;i++) {
        int u; cin >> u;
        e[u].push_back(i);
    }
    auto m = f(1);
    ll ans = 0;
    for (auto p : m) ans = (ans + p.first * p.second) % mod;
    cout << ans << endl;
}