// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
const int maxn = 2e5 + 10;
vector<int> e[maxn];
int a[maxn];
int r[maxn], f[maxn], com[maxn];
unordered_set<int> s[maxn];
int main() {
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i];
    while (m--) {
        int u, v; cin >> u >> v;
        if (a[u] > a[v]) swap(u, v);
        r[v]++; // 记录入度
        e[u].push_back(v);
    }
    queue<int> q;
    for (int i=2;i<=n;i++) if (!e[i].size()) q.push(i);
    while (!q.empty()) { // 去掉不相关的边
        int d = q.front(); q.pop();
        for (int v : e[d]) {
            r[v]--; if (r[v] == 0) q.push(v);
        }        
    }
    
    q.push(1); s[1].insert(a[1]);
    while (!q.empty()) {
        int d = q.front(); q.pop();
        for (int v : e[d]) {
            
            int t = s[d].size();
            if (s[d].find(a[v]) == s[d].end()) t++;
            if (t > f[v]) {
                f[v] = t, com[v] = d; // 暂时记录当前最大 复杂度 O(1)
            }
            r[v]--; if (r[v] == 0) {
                q.push(v);
                s[v] = s[com[v]]; s[v].insert(a[v]); // 全局最大
            }
        }
    }

    cout << s[n].size() << endl;
}