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
typedef pair<int, ll> P;

int n, m;
vector<P> e[15];
bool vis[15];
ll dfs (int v) {
    vis[v] = true;
    ll ans = 0;
    for (P d : e[v]) {
        if (!vis[d.first]) ans = max (ans, dfs(d.first) + d.second);
    }
    vis[v] = false;
    return ans;
}
int main() {
    cin >> n >> m;
    for (int i=0;i<m;i++) {
        int a, b, c; cin >> a >> b >> c;
        e[a].push_back ({b, c});
        e[b].push_back ({a, c});
    }
    ll ans = 0;
    for (int i=1;i<=n;i++) {
        ans = max (ans, dfs(i));
    }
    cout << ans << endl;
}