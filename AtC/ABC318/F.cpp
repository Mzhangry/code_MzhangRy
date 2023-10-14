// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll inf = 1e18;
int n;
int main() {
    cin >> n;
    vector<ll> x(n), l(n);
    for (int i=0;i<n;i++) cin >> x[i];
    for (int i=0;i<n;i++) cin >> l[i];
    ll ans = 0;
    
    for (int i=1;i<=n;i++) {
        ll left = -inf, right = inf; int cnt = 0;
        for (int j=0;j<=n;j++) {
            if (i-j-1 >= 0) right = min(right, x[i-j-1] + l[cnt++]);
            if (i+j < n) left = max(left, x[i+j] - l[cnt++]);
        }
        ans += min(x[i], right) - max(left, x[i-1]) + 1;
    }
    cout << ans << endl;
}