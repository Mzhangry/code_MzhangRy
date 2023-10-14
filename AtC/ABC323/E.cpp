// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 998244353;
int n, x;
void moplus (ll& a, ll b) {
    a = (a + b) % mod;
}
int main() {
    cin >> n >> x;
    vector< vector<ll> > f (x+1005+1, vector<ll> (n + 1));
    vector< ll > sum(x+1), t(n+1); sum[0] = 1;
    for (int i=1;i<=n;i++) cin >> t[i];
    for (int i=1;i<=x + 1005;i++) {
        for (int j=1;j<=n;j++) {
            if (t[j] <= i && i-t[j] <= x) moplus(f[i][j], sum[i-t[j]]);
            moplus(sum[i], f[i][j]);
        }
    }
    ll ans = 0, cnt1 = 0;
    for (int i=1;i<=x+1005;i++) moplus(ans, sum[i]);
    for (int i=x+1;i<=x+t[1];i++) moplus(cnt1, f[i][1]);
    cout << cnt1 << ' ' << ans << endl;
}