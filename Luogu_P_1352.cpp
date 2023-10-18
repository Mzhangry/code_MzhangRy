// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<int> r, fa;
const int maxn = 6e3 + 10;
int f[maxn][2];
vector<int> e[maxn];
void dfs (int d) {
    f[d][0] = 0; f[d][1] = r[d];
    for (int v : e[d]) {
        dfs(v);
        f[d][0] += max(f[v][0], f[v][1]);
        f[d][1] += f[v][0];
    }
}
int main() {
    cin >> n;
    r.resize(n+1); fa.resize(n+1);
    for (int i=1;i<=n;i++) cin >> r[i];
    for (int i=0;i<n-1;i++) {
        int u, v; cin >> v >> u;
        e[u].push_back(v);
        fa[v] = u;
    }
    int t = 1;
    while (fa[t]) t = fa[t];
    dfs(t);
    cout << max(f[t][0], f[t][1]) << endl;
}