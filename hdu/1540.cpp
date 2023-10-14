// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;

const int maxn = 5e4 + 10;
int n, m;
int pre[maxn << 2], suf[maxn << 2];
int tree[maxn << 2];
int ls (int p) {return p << 1;}
int rs (int p) {return p << 1 | 1;}
void push_up (int p, int pl, int pr) {
    int mid = (pl + pr) / 2;
    if (pre[ls(p)] == (mid - pl + 1)) pre[p] = mid - pl + 1 + pre[rs(p)];
    else pre[p] = pre[ls(p)];
    if (suf[rs(p)] == (pr - mid)) suf[p] = pr - mid + suf[ls(p)];
    else suf[p] = suf[rs(p)];
}
void build (int p, int pl, int pr) {
    if (pl == pr) {pre[p] = suf[p] = 1; return;}
    int mid = (pl + pr) / 2;
    build (ls(p), pl, mid); build (rs(p), mid + 1, pr);
    push_up (p, pl, pr);
}
void update (int p, int pl, int pr, int x, int d) {
    if (pl == pr) {pre[p] = suf[p] = d; return;}
    int mid = (pl + pr) / 2;
    if (x <= mid) update (ls(p), pl, mid, x, d);
    else update (rs(p), mid+1, pr, x, d);
    push_up(p, pl, pr);
}
int query (int p, int pl, int pr, int x) {
    if (pl == pr) return pre[p];
    int mid = (pl + pr) / 2, ans = 0;
    if (x <= mid) {
        if (mid - suf[ls(p)] < x) return suf[ls(p)] + pre[rs(p)];
        else return query(ls(p), pl, mid, x);
    } else {
        if (mid + pre[rs(p)] >= x) return suf[ls(p)] + pre[rs(p)];
        else return query(rs(p), mid+1, pr, x);
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    while (cin >> n >> m) {
        int des[maxn]; int cnt = 0;
        build (1, 1, n);
        while (m--) {
            char c; int x;
            cin >> c;
            if (c == 'D') {cin >> des[++cnt]; update (1, 1, n, des[cnt], 0);}
            else if (c == 'Q') {cin >> x; cout << query (1, 1, n, x) << endl;}
            else update (1, 1, n, des[cnt--], 1);
        }
    }
}