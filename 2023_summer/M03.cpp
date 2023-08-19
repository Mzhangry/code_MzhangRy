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

int main() {
    int n, k; cin >> n >> k;
    vector<ll> h(n);
    for (int i=0;i<n;i++) cin >> h[i];
    sort (h.begin(), h.end(), greater<int>());
    ll ans = 0, cnt = 0;
    for (int i=0;i<n-1;i++) {
        cnt += 1LL * (i+1) * (h[i] - h[i+1]);
        if (cnt >= k) {
            ll cut = (cnt - 1) / k + 1;
            ans += cut;
            cnt = 0;
        }
    }
    if (cnt) ans++;
    cout << ans << endl;
}