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
const int maxn = 1e6 + 10;

ll read() {
    ll x = 0, w = 1;
    char c = 0;
    while (!isdigit(c)) {
        if (c == '-') w = -1;
        c = getchar();
    }
    while (isdigit(c)) {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x * w;
}
ll a[maxn], mx[4*maxn], se[4*maxn], sum[4*maxn], cnt[4*maxn], tag[4*maxn];
int n, m;
int ls (int a) {return a << 1;}
int rs (int a) {return (a << 1) + 1;}
void push_up (int p) {
    int l = ls(p), r = rs(p);
    sum[p] = sum[l] + sum[r];
    if (mx[l] == mx[r]) {
        mx[p] = mx[l];
        cnt[p] = cnt[l] + cnt[r];
        se[p] = max(se[l], se[r]);
    } else {
        mx[p] = max(mx[l], mx[r]);
        cnt[p] = mx[l] > mx[r] ? cnt[l] : cnt[r];
        se[p] = min(mx[l], mx[r]);
    }
}

void build (int p, int pl, int pr) {
    if (pl == pr) {
        sum[p] = a[pl]; mx[p] = a[pl]; se[p] = -1; cnt[p] = 1;
        return;
    }
    int mid = (pl + pr) / 2;
    build (ls(p), pl, mid);
    build (rs(p), mid+1, pr);
    push_up(p);
}

void addtag (int p, ll d) {
    if (mx[p] <= d) return;
    sum[p] -= cnt[p] * (mx[p] - d);
    mx[p] = d;
}
void push_down (int p) {
    addtag (ls(p), mx[p]);
    addtag (rs(p), mx[p]);
}
void re (int p, int pl, int pr, int L, int R, ll d) {
    if (mx[p] <= d) return;
    else if (se[p] < d && L <= pl && R >= pr) {
        addtag (p, d);
        return;
    }
    push_down(p);
    int mid = (pl + pr) / 2;
    if (L <= mid) re (ls(p), pl, mid, L, R, d);
    if (R > mid) re (rs(p), mid+1, pr, L, R, d);
    push_up(p);
}

ll query_mx (int p, int pl, int pr, int L, int R) {
    if (L <= pl && R >= pr) return mx[p];
    push_down(p);
    int mid = (pl + pr) / 2;
    ll ans = -1;
    if (L <= mid) ans = max(ans, query_mx(ls(p), pl, mid, L, R));
    if (R > mid) ans = max(ans, query_mx(rs(p), mid+1, pr, L, R));
    return ans;
}
ll query_sum (int p, int pl, int pr, int L, int R) {
    if (L <= pl && R >= pr) return sum[p];
    push_down(p);
    int mid = (pl + pr) / 2;
    ll ans = 0;
    if (L <= mid) ans += query_sum(ls(p), pl, mid, L, R);
    if (R > mid) ans += query_sum (rs(p), mid+1, pr, L, R);
    return ans;
}
int main() {
    //ios::sync_with_stdio(false);
    int t = read();
    while (t--) {
        n = read(), m = read();
        for (int i=1;i<=n;i++) a[i] = read();
        build (1, 1, n);
        while (m--) {
            ll d = read(), l = read(), r = read(), x;
            if (d == 0) x = read();
            if (d == 0) re (1, 1, n, l, r, x);
            else if (d == 1) printf("%lld\n", query_mx(1, 1, n, l, r));
            else printf("%lld\n", query_sum(1, 1, n, l, r));
        }
    }
}