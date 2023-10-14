// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

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
vector< vector<int> > e;
vector<bool> vis, iss1;
vector<int> sx, iss;
int n = read(), m = read(), k = read(), q = read();
bool cmp (int a, int b) {
    return iss[a] < iss[b];
}
int num = 1;
// 节点周围的所有传感器置为-1即可（iss
bool dfs (int a) {
    vis[a] = true;
    if (iss[a] == -1) return dfs()
    bool flag = false;
    // vector<int> p;
    // for (int d : e[a]) if (!vis[d] && d == sx[num] && num++ && dfs(d)) flag = true;
    // if (num == k) return true;
    // for (int d : e[a]) {
    //     if (!vis[d] && !iss[d] && dfs(d)) flag = true;
    //     if (iss[d] && d != sx[num]) p.push_back(d);
    // }
    int cnt = 0;
    for (int d : e[a]) if (!vis[d] && iss[d] > 0) iss[d] = -1;
    // sort (p.begin(), p.end(), cmp);
    for (int d : e[a]) if (!vis[d]) {
        if (d == sx[num] && num++ && dfs(d)) flag = true;
        else break;
    }
    return flag;
}
void init () {
    num = 1;
    for (int i=1;i<=n;i++) {vis[i] = false;}
}
int main() {
    e.resize(n+1), iss.resize(n+1); sx.resize(k); vis.resize(n+1);
    for (int i=0;i<m;i++) {
        int u = read(), v = read();
        e[u].push_back(v), e[v].push_back(u);
    }
    for (int _=0;_<q;_++) {
        for (int i=0;i<k;i++) sx[i] = read();
        if (_ == 0) for (int i=0;i<k;i++) iss[sx[i]] = i;
        init();
        if (dfs(sx[0])) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}