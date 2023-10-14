// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
#define mid (pl+pr)/2
typedef long long ll;

const int maxn = 1e5 + 10;
int pre[2][maxn << 2], suf[2][maxn << 2], sum[maxn << 2], mx[2][maxn << 2];
bool tag[3][maxn << 2];
int n, m;
vector<int> a;
int ls(int p) {return p << 1;}
int rs(int p) {return p << 1 | 1;}
void nbclear (int p) {
    tag[0][p] = tag[1][p] = tag[2][p] = 0;
}
void push_up(int p, int pl, int pr) {
    sum[p] = sum[ls(p)] + sum[rs(p)];
    for (int _=0;_<=1;_++) {
        mx[_][p] = max(suf[_][ls(p)] + pre[_][rs(p)], max(mx[_][ls(p)], mx[_][rs(p)]));
        pre[_][p] = pre[_][ls(p)]; suf[_][p] = suf[_][rs(p)];
        if (pre[_][ls(p)] ==  mid - pl + 1) pre[_][p] += pre[_][rs(p)];
        if (suf[_][rs(p)] == pr - mid) suf[_][p] += suf[_][ls(p)];
    }
}
void build (int p, int pl, int pr) {
    if (pl == pr) {
        pre[a[pl]][p] = suf[a[pl]][p] = 1, pre[a[pl]^1][p] = suf[a[pl]^1][p] = 0; mx[0][p] = pre[0][p]; mx[1][p] = pre[1][p];
        nbclear(p);
        sum[p] = a[pl];
        return;
    }
    build (ls(p), pl, mid); build (rs(p), mid+1, pr);
    push_up(p, pl, pr);
}
void update (int p, int tag0, int tag1, int tag2, int pl, int pr) {
    int d;
    if (tag1) d = 1; else if (tag0) d = 0;
    if (tag2 && (tag[1][p] | tag[0][p])) {swap (tag[0][p], tag[1][p]); tag[2][p] = 0;}
    else if (tag2 && tag[2][p]) tag[2][p] = 0;
    else if (tag2) tag[2][p] = 1;
    if (tag1 | tag0) tag[d^1][p] = 0, tag[d][p] = 1, tag[2][p] = 0;

    if (tag[0][p]) {
        sum[p] = 0;
        pre[0][p] = suf[0][p] = mx[0][p] = pr - pl + 1;
        pre[1][p] = suf[1][p] = mx[1][p] = 0;
    } else if (tag[1][p]) {
        sum[p] = pr - pl + 1;
        pre[0][p] = suf[0][p] = mx[0][p] = 0;
        pre[1][p] = suf[1][p] = mx[1][p] = pr - pl + 1;
    }
    if (tag[2][p]) {
        sum[p] = pr - pl + 1 - sum[p];
        swap(pre[0][p], pre[1][p]); swap(suf[0][p], suf[1][p]); swap(mx[0][p], mx[1][p]);
    }
}
void push_down (int p, int pl, int pr) {
    update (ls(p), tag[0][p], tag[1][p], tag[2][p], pl, mid);
    update (rs(p), tag[0][p], tag[1][p], tag[2][p], mid+1, pr);
    nbclear(p);
}
void opchange (int p, int pl, int pr, int L, int R, int d) {
    if (L <= pl && R >= pr) {
        // if (d == 2 && (tag[1][p] | tag[0][p])) {swap (tag[0][p], tag[1][p]); tag[2][p] = 0;}
        // else if (d == 2 && tag[2][p]) tag[2][p] = 0;
        // else if (d == 2) tag[2][p] = 1;
        // if (d == 1 || d == 0) tag[d^1][p] = 0, tag[d][p] = 1, tag[2][p] = 0;
        update (p, d==0, d==1, d==2, pl, pr);
        return;
    }
    push_down(p, pl, pr);
    if (L <= mid) opchange(ls(p), pl, mid, L, R, d);
    if (R > mid) opchange(rs(p), mid + 1, pr, L, R, d);
    push_up(p, pl, pr);
}
int query3 (int p, int pl, int pr, int L, int R) {
    if (L <= pl && R >= pr) return sum[p];
    push_down(p, pl, pr); int sum = 0;
    if (L <= mid) sum += query3(ls(p), pl, mid, L, R);
    if (R > mid) sum += query3(rs(p), mid+1, pr, L, R);
    return sum;
}
int query4 (int p, int pl, int pr, int L, int R) {
    if (L <= pl && R >= pr) return mx[1][p];
    push_down(p, pl, pr);
    if (R <= mid) return query4(ls(p), pl, mid, L, R); if (L > mid) return query4(rs(p), mid+1, pr, L, R);
    int l = query4(ls(p), pl, mid, L, R);
    int r = query4(rs(p), mid+1, pr, L, R);
    int ans3 = min(mid - L + 1, suf[1][ls(p)]) + min(R - mid, pre[1][rs(p)]);
    return max(ans3, max(l, r));
}
int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        memset (tag, 0, sizeof(tag));
        cin >> n >> m;
        a.resize(n+1); for (int i=1;i<=n;i++) cin >> a[i];
        build (1, 1, n);
        while (m--) {
            int q, a, b; cin >> q >> a >> b; a++; b++;
            if (q == 0 || q == 1 || q == 2) opchange (1, 1, n, a, b, q);
            else if (q == 3) cout << query3(1, 1, n, a, b) << endl;
            else cout << query4(1, 1, n, a, b) << endl;
        }
    }
}