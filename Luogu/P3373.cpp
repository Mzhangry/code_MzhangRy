// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, q, mod;
const int maxn = 1e5 + 10;
ll tree[maxn << 2], tagp[maxn << 2], tagm[maxn << 2];
vector<ll> a;

void moplus (ll& a, ll b) {a = (a + (b%mod)) % mod;}
void momul (ll& a, ll b) {a = (a * (b%mod)) % mod;}
int ls(int p) {return p << 1;}
int rs(int p) {return p << 1 | 1;}
void push_up (int p) {
    tree[p] = (tree[ls(p)] + tree[rs(p)]) % mod;
}
void build (int p, int pl, int pr) {
    tagm[p] = 1;
    if (pl == pr) {tree[p] = a[pl]; return;}
    int mid = (pl + pr) / 2;
    build (ls(p), pl, mid); build (rs(p), mid+1, pr);
    push_up(p);
}
void addtagp (int p, int pl, int pr, ll d) {
    moplus (tree[p], d * (pr - pl + 1));
    moplus (tagp[p], d);
}
void addtagm (int p, int pl, int pr, ll d) {
    momul (tagp[p], d);
    momul (tree[p], d);
    momul (tagm[p], d);
}
void push_down (int p, int pl, int pr) {
    int mid = (pl + pr) / 2;
    addtagm (ls(p), pl, mid, tagm[p]); addtagm (rs(p), mid+1, pr, tagm[p]);
    addtagp (ls(p), pl, mid, tagp[p]); addtagp (rs(p), mid+1, pr, tagp[p]);
    tagm[p] = 1; tagp[p] = 0;
}
void add (int p, int pl, int pr, int L, int R, ll d) {
    if (L <= pl && R >= pr) {
        addtagp (p, pl, pr, d);
        return;
    }
    push_down(p, pl, pr);
    int mid = (pl + pr) / 2;
    if (L <= mid) add (ls(p), pl, mid, L, R, d);
    if (R > mid) add (rs(p), mid+1, pr, L, R, d);
    push_up(p);
}
void mul (int p, int pl, int pr, int L, int R, ll d) {
    if (L <= pl && R >= pr) {
        addtagm (p, pl, pr, d);
        return;
    }
    push_down(p, pl, pr);
    int mid = (pl + pr) / 2;
    if (L <= mid) mul (ls(p), pl, mid, L, R, d);
    if (R > mid) mul (rs(p), mid+1, pr, L, R, d);
    push_up(p);
}
ll query (int p, int pl, int pr, int L, int R) {
    if (L <= pl && R >= pr) return tree[p];
    push_down(p, pl, pr);
    int mid = (pl + pr) / 2; ll ans = 0;
    if (L <= mid) moplus (ans, query(ls(p), pl, mid, L, R));
    if (R > mid) moplus(ans, query(rs(p), mid+1, pr, L, R));
    return ans;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> q >> mod;
    a.resize(n+1); for (int i=1;i<=n;i++) cin >> a[i];
    build (1, 1, n);
    while (q--) {
        ll x, y, k, t; cin >> t >> x >> y; 
        if (t == 1) {cin >> k; mul(1, 1, n, x, y, k);}
        else if (t == 2) {cin >> k; add(1, 1, n, x, y, k);}
        else cout << query(1, 1, n, x, y) << endl;
    }
}