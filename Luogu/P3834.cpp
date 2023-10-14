// MzhangRy - 张容钰
// 模版 可持久化线段树
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mid ((pl + pr) >> 1)

const int maxn = 2e5 + 10;
int n, m;
int a[maxn], b[maxn], root[maxn];
struct Point {
    int L, R; int sum = 0;
} tree[maxn << 5];
int cnt = 0;
int read() {
  int x = 0, w = 1;
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
int update (int pre, int pl, int pr, int d) {
    int rt = ++cnt;
    tree[rt].L = tree[pre].L; tree[rt].R = tree[pre].R;
    tree[rt].sum = tree[pre].sum+1;
    if (pl == pr) return rt;
    if (d <= mid) tree[rt].L = update (tree[pre].L, pl, mid, d);
    else tree[rt].R = update (tree[pre].R, mid+1, pr, d);
    return rt;
}
int query (int u, int v, int pl, int pr, int k) { // u v是线段数根节点编号
    if (pl == pr) return pl;
    int x = tree[tree[v].L].sum - tree[tree[u].L].sum; // 左边有几个
    if (x >= k) return query(tree[u].L, tree[v].L, pl, mid, k);
    else return query(tree[u].R, tree[v].R, mid+1, pr, k-x);
}
int main() {
    // freopen("P3834_3.in", "r", stdin);
    // freopen("P3834.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i=1;i<=n;i++) {cin >> a[i]; b[i] = a[i];}
    sort(b+1, b+1+n);
    int size = unique(b+1, b+1+n) - (b+1);
    for (int i=1;i<=n;i++) {
        int x = lower_bound(b+1, b+1+size, a[i]) - (b);
        root[i] = update(root[i-1], 1, size, x);
    }
    while (m--) {
        int l, r, k; cin >> l >> r >> k;
        int num = query(root[l-1], root[r], 1, size, k);
        cout << b[num] << endl;
    }
}