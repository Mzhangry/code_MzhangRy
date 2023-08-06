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

ll l, n, m;
int main() {
    cin >> l >> n >> m;
    vector<ll> a, b, mula, mulb;
    for (int i=0;i<n;i++) {
        ll x, y; cin >> x >> y;
        a.push_back(x); mula.push_back(y);
    }
    for (int i=0;i<m;i++) {
        ll x, y; cin >> x >> y;
        b.push_back(x); mulb.push_back(y);
    }
    vector<ll> suma(n+1), sumb(m+1);
    for (int i=0;i<n;i++) suma[i+1] = suma[i] + mula[i];
    for (int i=0;i<m;i++) sumb[i+1] = sumb[i] + mulb[i];
    ll ta=1, tb=1;
    ll ans = 0;
    while (ta <= n && tb <= m) {
        if (a[ta-1] == b[tb-1]) ans += min(suma[ta], sumb[tb]) - max(suma[ta-1], sumb[tb-1]);
        if (suma[ta] == sumb[tb]) {
            ta++; tb++;
        } else if (suma[ta] < sumb[tb]) {
            ta++;
        } else {
            tb++;
        }
    }
    cout << ans << endl;
}