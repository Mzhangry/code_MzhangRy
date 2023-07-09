// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int n, m;
vector<int> e[100005];
bool vis[100005];
int que[100005], head, tail;
int ans = 0;
int main() {
    cin >> n >> m;
    for (int i=0;i<m;i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    que[tail++] = 1; vis[1] = true; ans++;
    while (head < tail) {
        int d = que[head];
        head++;
        for (int i=0;i<e[d].size();i++) if (!vis[e[d][i]]) {
            que[tail++] = e[d][i];
            ans++;
            vis[e[d][i]] = true;
        }
    }
    cout << ans;
}