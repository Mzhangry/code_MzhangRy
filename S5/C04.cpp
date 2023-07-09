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
int dis[100005];
const int inf = 1e8;
vector<int> e[100005];
int que[100005], head, tail;
int main() {
    cin >> n >> m;
    for (int i=0;i<m;i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    for (int i=0;i<=n;i++) dis[i] = inf;
    que[tail++] = 1;
    dis[1] = 0;
    while (head < tail) {
        int d = que[head++];
        for (int i=0;i<e[d].size();i++) {
            int v = e[d][i];
            if (dis[v] > dis[d] + 1) {
                dis[v] = dis[d] + 1;
                que[tail++] = v;
            }
        }
    }
    if (dis[n] == inf) cout << -1;
    else cout << dis[n];
}