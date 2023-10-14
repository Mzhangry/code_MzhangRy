// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5 + 10, maxm = 4e5 + 10;
int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}
int n, m, k, q;
int cnt = 0;
struct Edge {
    int to, next = -1;
} e[maxm];
int head[maxn], fa[maxn], xl[maxn]; bool vis[maxn];
void init () {
    for (int i=0;i<=n;i++) fa[i] = i, vis[i] = false;
}
bool iss[maxn];
    void init_nots () {
        for (int i=1;i<=k;i++) iss[xl[i]] = true;
    }
int find (int a) {
    return a == fa[a] ? a : fa[a] = find(fa[a]);
}
void merge (int u, int v) {
    // cout << "merge" << ' ' << u << ' ' << v << endl;
    u = find(u), v = find(v);
    if (u != v) fa[u] = fa[v];
}
void build (int u, int v) {
    e[++cnt].next = head[u]; 
    e[cnt].to = v;
    head[u] = cnt;
}
int main() {
    cin >> n >> m >> k >> q;
    for (int i=0;i<=n;i++) head[i] = -1;
    for (int i=0;i<m;i++) {
        int u = read(), v = read();
        build (u, v); build (v, u);
    }
    for (int _=0;_<q;_++) {
        init();
        for (int i=1;i<=k;i++) xl[i] = read();
        if (_ == 0) init_nots();
        for (int i=1;i<=n;i++) { // 将非传感器合并
            if (!iss[i] && !vis[i]) {
                vis[i] = true;
                for (int d=head[i]; d != -1;d = e[d].next) if (!iss[e[d].to]) {
                    vis[e[d].to] = true;
                    merge(i, e[d].to);
                }
            }
        }
        bool flag = true;
        for (int i=1;i<=k;i++) {
            vis[xl[i]] = true;
            for (int d = head[xl[i]]; d != -1; d = e[d].next) if (vis[e[d].to]) {
                merge (xl[i], e[d].to);
            }
            if (i!=1 && find(xl[i]) != find(xl[i-1])) flag = false;
        }
        cout << (flag ? "Yes" : "No") << endl;
    }
}