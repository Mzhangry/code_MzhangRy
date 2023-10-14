// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, p;
int main() {
    cin >> n >> m >> p;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < m; j++) cin >> b[j];
    vector<ll> sum(m);
    sort(b.begin(), b.end());
    for (int i = 0; i < m; i++) {
        sum[i] = b[i];
        if (i > 0) sum[i] += sum[i - 1];
    }
    ll ans = 0;
    for (int i=0;i<n;i++) {
        int id = upper_bound(b.begin(), b.end(), p - a[i]) - b.begin();
        if (id != 0) ans += a[i]*(id) + sum[id - 1];
        ans += p*(m-id);
    }
    cout << ans << endl;
}