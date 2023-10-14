// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    unordered_map<int, ll> m;
    for (int i=0;i<n;i++) {
        ll s, c; cin >> s >> c;
        while (!(s & 1)) s >>= 1, c <<= 1;
        m[s] += c;
    }
    ll ans = 0;
    for (auto d : m) {
        while (d.second) ans += d.second & 1, d.second >>= 1;
    }
    cout << ans << endl;
}