// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, x, y;
int main() {
    cin >> n >> x >> y;
    vector<int> p(n), t(n);
    for (int i=1;i<=n-1;i++) cin >> p[i] >> t[i];
    vector<ll> ans(840);
    for (int i=0;i<840;i++) { // 起始时间
        ll tim = i; tim += x;
        for (int j=1;j<=n-1;j++) {
            tim += (p[j] - tim % p[j]) % p[j] + t[j];
        }
        ans[i] = tim + y - i;
    }
    int q; cin >> q;
    for (int i=1;i<=q;i++) {
        ll d; cin >> d;
        cout << d + ans[d % 840] << endl;
    }
}