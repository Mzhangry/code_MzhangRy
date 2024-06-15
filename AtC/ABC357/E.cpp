// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;

signed main() {
    ll n; cin >> n;
	ll tmp = n, base = 1;
	while(tmp) base = base * 10 % mod, tmp = tmp / 10;
	ll k = n, up = 1, ans = 0;
	while(n) {
		if(n & 1) ans = (ans + k * up % mod) % mod, up = up * base % mod;
		n >>= 1;
		k = (k * base + k) % mod;
		base = base * base % mod;
	}
	cout << ans;
	return 0;
}