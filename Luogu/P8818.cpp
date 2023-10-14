// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mid ((pl + pr) >> 1)

int n, m, q;
const int maxn = 1e5 + 10;
const int inf = 1e9 + 10;
int a[2][maxn];
int mx[2][maxn << 2], mi[2][maxn << 2]; // , cntp[2][maxn << 2];
int minabs[2][maxn << 2];
int ls (int p) {return p << 1;}
int rs (int p) {return p << 1 | 1;}
void push_up (int p, bool B) {
    mx[B][p] = max(mx[B][ls(p)], mx[B][rs(p)]);
    mi[B][p] = min(mi[B][ls(p)], mi[B][rs(p)]);
    if (!B) minabs[0][p] = min(minabs[0][ls(p)], minabs[0][rs(p)]),
            minabs[1][p] = min(minabs[1][ls(p)], minabs[1][rs(p)]);
    // cntp[B][p] = cntp[B][ls(p)] + cntp[B][rs(p)];
}
void build (int p, int pl, int pr, bool B) {
    if (pl == pr) {mx[B][p] = mi[B][p] = a[B][pl]; if (!B) minabs[a[0][pl] >= 0][p] = abs(a[0][pl]); return;}
    build (ls(p), pl, mid, B); build (rs(p), mid + 1, pr, B);
    push_up (p, B);
}
int query_max (int p, int pl, int pr, int L, int R, int B) {
    if (L <= pl && R >= pr) return mx[B][p];
    int ans = -1e9 - 10;
    if (L <= mid) ans = max (ans, query_max(ls(p), pl, mid, L, R, B));
    if (R > mid) ans = max(ans, query_max(rs(p), mid + 1, pr, L, R, B));
    return ans;
}
int query_min (int p, int pl, int pr, int L, int R, int B) {
    if (L <= pl && R >= pr) return mi[B][p];
    int ans = 1e9+10;
    if (L <= mid) ans = min (ans, query_min(ls(p), pl, mid, L, R, B));
    if (R > mid) ans = min(ans, query_min(rs(p), mid + 1, pr, L, R, B));
    return ans;
}
int query_abs (int p, int pl, int pr, int L, int R, bool B) {
    if (L <= pl && R >= pr) return minabs[B][p];
    int ans = 1e9+10;
    if (L <= mid) ans = min (ans, query_abs(ls(p), pl, mid, L, R, B));
    if (R > mid) ans = min(ans, query_abs(rs(p), mid + 1, pr, L, R, B));
    return ans;
}
int main() {
    // freopen ("game4.in", "r", stdin);
    // freopen ("game.out", "w", stdout);
    for (int i=0;i<=1;i++) for (int j=0;j<(maxn << 2);j++) minabs[i][j] = inf;
    cin >> n >> m >> q;
    for (int i=1;i<=n;i++) cin >> a[0][i];
    for (int i=1;i<=m;i++) cin >> a[1][i];
    build (1, 1, n, 0); build (1, 1, m, 1);
    while (q--) {
        int la, ra, lb, rb; cin >> la >> ra >> lb >> rb;
        int amin = query_min(1, 1, n, la, ra, 0),
            amax = query_max(1, 1, n, la, ra, 0),
            bmin = query_min(1, 1, m, lb, rb, 1),
            bmax = query_max(1, 1, m, lb, rb, 1),
            mabsP = query_abs(1, 1, n, la, ra, 1),
            mabsN = query_abs(1, 1, n, la, ra, 0);
        if (bmin >= 0) cout << 1LL * amax * (amax < 0 ? bmax : bmin) << endl;
        else if (bmax < 0) cout << 1LL * amin * (amin < 0 ? bmax : bmin) << endl;
        else {
            if (amin >= 0) cout << 1LL * amin * bmin << endl;
            else if (amax < 0) cout  << 1LL * amax * bmax << endl;
            else cout << -1 * min (1LL * mabsP * abs(bmin), 1LL * mabsN * bmax) << endl;
        }
    }
}