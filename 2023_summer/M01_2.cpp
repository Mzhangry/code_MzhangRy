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


vector<ll> c, v;
ll n, l;

ll solve (ll a) {
    if (a == 0) return 0;
    auto it = upper_bound(v.begin(), v.end(), a);
    ll ans1 = it == v.end() ? c[n] * (a / v[n] + 1) : c[it - v.begin()], ans2 = 0;
    for (int id = it - v.begin() - 1; id >= 1; id--) {
        if (a >= v[id]) {
            ll num = a / v[id];
            a -= v[id] * num;
            ans2 += c[id] * num;
        } else {
            ans2 += solve(a);
            break;
        }
    }
    return min(ans1, ans2);
}

int main() {
    cin >> n >> l;
    c.resize(n+1); v.resize(n+1); v[1] = 1;
    for (int i=1;i<=n;i++) cin >> c[i];
    for (int i=2;i<=n;i++) v[i] = v[i-1] * 2;
    ll last = c[1];
    for (int i=2;i<=n;i++) {
        if (last * 2 < c[i]) c[i] = last * 2;
        for (int j=i-1;j>=1 && c[i] < c[j];j--) {
            c[j] = c[i];
        }
        last = c[i];
    }

    cout << solve(l) << endl;
}