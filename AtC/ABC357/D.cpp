// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int n;
const int maxn = 2e5 + 10;
int e[maxn];

bool vis[maxn];
unordered_set<int> circle;
int siz[maxn];
int dfsC(int a) {
    if (siz[a]) return 0;
    if (vis[a]) {
        circle.insert(a);
        return a;
    }
    vis[a] = true;
    return dfsC(e[a]);
}


int dfs (int a) {
    if (siz[a]) return siz[a];
    return (siz[a] = dfs(e[a]) + 1);
}
int main() {
    cin >> n;
    for (int i=1;i<=n;i++) {
        cin >> e[i];
    }
    
    for (int i=1;i<=n;i++) if (!vis[i]) {
        int t = dfsC(i);
        if (!siz[t] && circle.size()) {
            while (circle.find(e[t]) == circle.end()) {
                t = e[t]; circle.insert(t);
            }
            for (auto i : circle) {
                siz[i] = circle.size();
            }
        }
        siz[i] = dfs(i);
        circle.clear();
    }
    ll ans = 0;
    for (int i=1;i<=n;i++) {
        ans += dfs(i);
    }
    cout << ans << endl;
}