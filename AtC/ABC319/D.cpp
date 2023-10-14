// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> l(n+1); 
    for (int i=1;i<=n;i++) cin >> l[i];
    // vector<ll> sum(n+1);
    // for (int i=1;i<=n;i++) sum[i] = sum[i-1] + l[i];
    ll left = 1, right = 1e17;
    ll ans = 1e18;
    while (left < right) {
        ll mid = (left + right) / 2;
        int cnt = 1; ll len = -1;
        bool flag = true;
        for (int i=1;i<=n;i++) {
            if (mid < l[i]) {flag = false; break;}
            if (len + l[i] + 1 <= mid) len += l[i] + 1;
            else {
                cnt++;
                len = l[i];
            }
        }
        
        if (cnt > m || ! flag) left = mid + 1;
        else {right = mid; ans = min(ans, mid);}
    }
    cout << ans << endl;
}