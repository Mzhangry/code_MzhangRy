// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, x, k;
ll cnt = 1;
ll mul2[70] = {1};
void init() {
    for (int i=1;i<=62;i++) mul2[i] = mul2[i-1] << 1;
    mul2[63] = mul2[64] = 9223372036854775807-1;
}
int log2 (ll a) {
    return upper_bound(mul2, mul2+64, a) - mul2 - 1;
}
void culheight() {
    cnt = mul2[log2(n+1)+1]-1;
    return;
}
ll read() {
    ll x = 0, w = 1;
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

ll f(ll p, ll dis, bool l, bool r) { // p下面有多少个距离p为 dis 的点
    if (dis > 63) return 0;
    if (LLONG_MAX/p < mul2[dis]) return 0; // 防止溢出
    p = p * mul2[dis]; if (p > cnt) return 0;
    ll k = mul2[dis], ans = 0;
    if (l) ans += max(1LL*0, min(k/2, n+1-p));
    if (r) ans += max(1LL*0, min(k/2, n-k/2-p+1));
    return ans;
}
ll fu(ll p, ll dis, ll las) {
    if (dis == 0) return 1;
    ll ans = 0;
    if (las != -1) ans += f(p, dis, las%2==1, las%2==0);
    if (p != 1) ans += fu(p/2, dis-1, p);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    init();
    int t = read();
    while (t--) {
        n = read(), x = read(), k = read();
        culheight();
        cout << f(x, k, 1, 1) + fu(x, k, -1) << endl;
    }
}