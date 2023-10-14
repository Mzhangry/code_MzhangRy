#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int read() {
    int x = 0, w = 1;
    char c = 0;
    while (c < '0' || c > '9') {
        if (c == '-') w = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * w;
}
ll n, m;
vector<ll> a(n+1), b(n+1);

ll solve1() {
    ll mi = 1e9 + 10;
    for (int i=1;i<=n;i++) mi = min(mi, max(a[i], b[i]));
    return mi;
}
bool check (ll num) {
    ll sum_cnt = 0;
    for (int i=1;i<=n;i++) {
        ll d = num;
        if (a[i] > b[i]) {
            if ((d - 1) / a[i] + 1 > m) sum_cnt += m, d -= m * a[i];
            else sum_cnt += (d-1) / a[i] + 1, d = 0;
        }
        if (d > 0) sum_cnt += (d-1) / b[i] + 1;
        if (sum_cnt > n * m) return false;
    }
    return true;
}
int main() {
    // freopen("D.in", "r", stdin);
    n = read(), m = read();
    a.resize(n+1); b.resize(n+1);
    
    for (int i=1;i<=n;i++) a[i] = read();
    for (int i=1;i<=n;i++) b[i] = read();
    if (m == 1) {cout << solve1() << endl; return 0;}

    ll l = 1, r = 1e18 + 200, mid;
    ll ok = 0;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (check(mid)) ok = mid, l = mid+1;
        else r = mid - 1;
    }
    cout << ok << endl;
}
