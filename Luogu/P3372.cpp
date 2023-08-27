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
const int maxn = 1e5 + 10;

ll a[maxn];
ll tree[4*maxn];
ll tag[4*maxn];
int ls (int a) {return a << 1;}
int rs (int a) {return (a << 1) + 1;};
void push_up(int q) {
    tree[q] = tree[ls(q)] + tree[rs(q)];
}
void build (int q, int L, int R) {
    if (L == R) {tree[q] = a[L]; return;}
    int mid = (L + R) / 2;
    build (ls(q), L, mid);
    build (rs(q), mid+1, R);
    push_up(q);
}
void addtag (int q, int lq, int rq, int d) {
    tag[q] += d;
    tree[q] += d * (rq - lq + 1);
}
void push_down (int q, int lq, int rq) {
    if (tag[q]) {
        int mid = (lq + rq) / 2;
        addtag (ls(q), lq, mid, tag[q]);
        addtag (rs(q), mid + 1, rq, tag[q]);
        tag[q] = 0;
    }
}
void add (int q, int lq, int rq, int L, int R, ll d) {
    if (lq >= L && rq <= R) {
        addtag (q, lq, rq, d);
        return;
    }
    push_down(q, lq, rq);
    int mid =  (lq + rq) / 2;
    if (L <= mid) add (ls(q), lq, mid, L, R, d);
    if (R > mid) add (rs(q), mid+1, rq, L, R, d);
    push_up(q);
}
ll query (int q, int lq, int rq, int L, int R) {
    if (lq >= L && rq <= R) return tree[q];
    push_down(q, lq, rq);
    int mid = (lq + rq) / 2;
    ll ans = 0;
    if (L <= mid) ans += query(ls(q), lq, mid, L, R);
    if (R > mid) ans += query(rs(q), mid+1, rq, L, R);
    return ans; 
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i];
    build (1, 1, n);
    while (m--) {
        int d; ll x, y, k;
        cin >> d;
        if (d == 1) {
            cin >> x >> y >> k;
            add (1, 1, n, x, y, k);
        } else {
            cin >> x >> y;
            cout << query(1, 1, n, x, y) << endl;
        }
    }
}