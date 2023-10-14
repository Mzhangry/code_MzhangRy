// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mid ((pl + pr) / 2)

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
const int maxn = 1e6 + 10;
struct Point {
    int L, R; int v;
} tree[maxn << 5];
int a[maxn], root[maxn];
int n, m;
int cnt = 0;
int build (int pl, int pr) {
    int p = ++cnt;
    if (pl == pr) {tree[p].v = a[pl]; return p;}
    tree[p].L = build (pl, mid); 
    tree[p].R = build (mid+1, pr);
    return p;
}
int update (int pre, int pl, int pr, int num, int d) {
    int p = ++cnt; tree[p].L = tree[pre].L, tree[p].R = tree[pre].R;
    if (pl == pr) {tree[p].v = d; return p;}
    if (num <= mid) tree[p].L = update (tree[pre].L, pl, mid, num, d);
    else tree[p].R = update (tree[pre].R, mid+1, pr, num, d);
    return p;
}
int query (int p, int pl, int pr, int num) {
    if (pl == pr) return tree[p].v;
    if (num <= mid) return query (tree[p].L, pl, mid, num);
    else return query (tree[p].R, mid+1, pr, num);
}
int main() {
    ios::sync_with_stdio(false);
    n = read(), m = read();
    for (int i=1;i<=n;i++) a[i] = read();
    root[0] = build (1, n);
    for (int i=1;i<=m;i++) {
        int v = read(), t = read(), loc = read(), d;
        if (t == 2) { 
            cout << query (root[v], 1, n, loc) << endl;
            root[i] = root[v];
        } else {
            d = read();
            root[i] = update (root[v], 1, n, loc, d);
        }
    }
}