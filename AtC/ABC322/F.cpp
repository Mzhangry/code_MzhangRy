// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mid ((pl + pr) >> 1)

int n, q; string s;
const int maxn = 5e5 + 10;
int len[2][maxn << 2], head[2][maxn << 2], tail[2][maxn << 2], tag[maxn << 2];
int ls (int p) {return p << 1;}
int rs (int p) {return p << 1 | 1;}

void push_up (int p, int pl, int pr) {
    for (int d : {0, 1}) {
        head[d][p] = head[d][ls(p)] + (head[d][ls(p)] == (mid - pl) + 1 ? head[d][rs(p)] : 0);
        tail[d][p] = tail[d][rs(p)] + (tail[d][rs(p)] == (pr - mid) ? tail[d][ls(p)] : 0);
        len[d][p] = max(len[d][ls(p)], len[d][rs(p)]);
        len[d][p] = max(len[d][p], max(head[d][p], tail[d][p]));
        len[d][p] = max(len[d][p], tail[d][ls(p)] + head[d][rs(p)]);
    }
}
void build (int p, int pl, int pr) {
    if (pl == pr) {head[s[pl] - '0'][p] = tail[s[pl] - '0'][p] = len[s[pl] - '0'][p] = 1; return;}
    build (ls(p), pl, mid); build (rs(p), mid + 1, pr);
    push_up(p, pl, pr);
}

void add_tag (int p) {
    tag[p] = tag[p] ? 0 : 1;
    swap (len[0][p], len[1][p]);
    swap (head[0][p], head[1][p]);
    swap (tail[0][p], tail[1][p]);
}
void push_down (int p) {
    if (tag[p]) {
        add_tag (ls(p)); add_tag(rs(p));
        tag[p] = 0;
    }
}
void update (int p, int pl, int pr, int L, int R) {
    if (pl >= L && pr <= R) {add_tag(p); return;}
    push_down(p);
    if (L <= mid) update(ls(p), pl, mid, L, R);
    if (R > mid) update(rs(p), mid+1, pr, L, R);
    push_up(p, pl, pr);
}
int query (int p, int pl, int pr, int L, int R) {
    if (pl >= L && pr <= R) return len[1][p];
    push_down(p);
    int ans = 0;
    if (L <= mid && R > mid) ans = min (mid - L + 1, tail[1][ls(p)]) + min (R - mid, head[1][rs(p)]);
    if (L <= mid) ans = max(ans, query(ls(p), pl, mid, L, R));
    if (R > mid) ans = max(ans, query(rs(p), mid+1, pr, L, R));
    return ans;
}
int main() {
    cin >> n >> q;
    cin >> s; s += ' ';
    for (int i=n;i>=1;i--) s[i] = s[i-1];
    build(1, 1, n);
    while (q--) {
        int t, l, r; cin >> t >> l >> r;
        if (t == 1) update(1, 1, n, l, r);
        else cout << query(1, 1, n, l, r) << endl;
    }
}