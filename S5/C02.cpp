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
int main() {
    cin >> n >> m;
    for (int i=0;i<m;i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int ans = 0;
    for (int i=1;i<=n;i++) {
        if (!vis[i]) {
            que[tail++] = i;
            vis[i] = true;
            ans++;
            while (head < tail) {
                int d = que[head];
                for (int j=0;j<e[d].size();j++) if (!vis[e[d][j]]) {
                    que[tail++] = e[d][j];
                    vis[e[d][j]] = true;
                }
                head++;
            }
        }
    }
    cout << ans << endl;
}