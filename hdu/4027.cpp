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
const ll maxn = 1e5 + 10;

//vector<ll> tree; vector<ll> a;
ll tree[maxn*4], a[maxn];
ll ls (ll a) {return a << 1;}
ll rs (ll a) {return (a << 1) + 1;}
ll read() {
  ll x = 0, w = 1;
  char ch = 0;
  while (ch < '0' || ch > '9') {  // ch 不是数字时
    if (ch == '-') w = -1;        // 判断是否为负
    ch = getchar();               // 继续读入
  }
  while (ch >= '0' && ch <= '9') {  // ch 是数字时
    x = x * 10 + (ch - '0');  // 将新读入的数字「加」在 x 的后面
    // x 是 int 类型，char 类型的 ch 和 '0' 会被自动转为其对应的
    // ASCII 码，相当于将 ch 转化为对应数字
    // 此处也可以使用 (x<<3)+(x<<1) 的写法来代替 x*10
    ch = getchar();  // 继续读入
  }
  return x * w;  // 数字 * 正负号 = 实际数值
}

void push_up (ll p) {
    tree[p] = tree[ls(p)] + tree[rs(p)];
}
void build (ll p, ll pl, ll pr) {
    if (pl == pr) {
        tree[p] = a[pl];
        return;
    }
    ll mid = (pl + pr) / 2;
    build (ls(p), pl, mid);
    build (rs(p), mid+1, pr);
    push_up (p);
}
void re (ll p, ll pl, ll pr, ll L, ll R) {
    if (tree[p] == pr - pl + 1) return;
    if (pl == pr) {
        tree[p] = sqrtl(tree[p]);
        return;
    }
    ll mid = (pl + pr) / 2;
    if (L <= mid) re (ls(p), pl, mid, L, R);
    if (R > mid) re (rs(p), mid+1, pr, L, R);
    push_up (p);
}
ll query (ll p, ll pl, ll pr, ll L, ll R) {
    if (L <= pl && R >= pr) return tree[p];
    ll mid = (pl + pr) / 2;
    ll ans = 0;
    if (L <= mid) ans += query (ls(p), pl, mid, L, R);
    if (R > mid) ans += query (rs(p), mid+1, pr, L, R);
    return ans;
}
int main() {
    std::ios::sync_with_stdio(false);
    ll n; ll cnt = 0;
    while (cin >> n) {
        cnt ++; cout << "Case #" << cnt << ':' << endl;
        // tree.clear(); tree.resize(n*4+1);
        // a.clear(); a.resize(n+1);
        for (ll i=1;i<=n;i++) a[i] = read();
        build (1, 1, n);
        ll m = read();
        while (m--) {
            ll t = read(), x = read(), y = read(); if (x > y) swap(x, y);
            if (t == 0) {
                re (1, 1, n, x, y);
            } else {
                cout << query (1, 1, n, x, y) << endl;
            }
        }
        cout << endl;
    }
}