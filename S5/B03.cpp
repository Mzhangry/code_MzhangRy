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
vector<int> e[100005];
bool vis[100005];

void dfs(int a) {
    vis[a] = true;
    ans++;

    for (int i: e[a]) {
        if (!vis[i]) dfs(i);
    }
}
int main() {
    cin >> n >> m;
    for (int i=0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1);
    cout << ans;
}