// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int n, m, ans = 0;
vector<int> a[100005];
bool vis[100005];
void dfs (int p) {
    vis[p] = true;
    for (int i: a[p]) {
        if (!vis[i]) dfs(i);
    }
}
int main() {
    cin >> n >> m;
    for (int i=0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i=1;i<=n;i++) {
        if (!vis[i]) {
            dfs(i);
            ans++;
        }
    }
    cout << ans;
}