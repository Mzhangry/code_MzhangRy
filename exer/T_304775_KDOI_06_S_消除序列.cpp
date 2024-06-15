// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<int> a, b, c;
int q;
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
int main() {
    // freopen ("reserve8.in", "r", stdin);
    // freopen ("reserve8.out", "w", stdout);
    n = read();
    a.resize(n+1); b.resize(n+1); c.resize(n+1);
    for (int i=1;i<=n;i++) a[i] = read(); // 前i个设成0的代价
    for (int i=1;i<=n;i++) b[i] = read(); // 第i个设成0的代价
    for (int i=1;i<=n;i++) c[i] = read(); // 第i个设成1的代价
    for (int i=1;i<=n;i++) a[i] = min(a[i], a[i-1] + b[i]), a[i-1] = min(a[i-1], a[i] + c[i]); // 前i个设成0的代价
    vector<ll> head (n+1), tail (n+2);
    for (int i=1;i<=n;i++) head[i] = head[i-1] + c[i]; // 头部变为1的代价
    for (int i=n;i>=0;i--) tail[i] = tail[i+1] + b[i]; // 尾部变为0的代价
    q = read();
    while (q--) {
        ll ans = 1e18;
        int m; cin >> m;
        vector<int> p (m); 
        for (int i=0;i<m;i++) p[i] = read(); p.push_back(n+1); m++;
        ll sh1 = 0, st1 = 0;
        for (int i=0;i<m;i++) st1 += b[p[i]]; // 尾部不需要改为0的sum
        for (int i : p) {
            ll he = a[i-1] + sh1, ta = tail[i] - st1;
            sh1 += c[i], st1 -= b[i];
            ans = min(ans, he + ta);
        }
        cout << ans << endl;
    }
}