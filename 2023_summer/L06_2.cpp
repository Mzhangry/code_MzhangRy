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
const ll mod = 1e9+7;

int n;
ll mod_plus (ll a, ll b) {
    return (a + b) % mod;
}
int main() {
    cin >> n;
    vector<ll> a(n+1), sum(n+1);
    vector< vector<ll> > f(n+1, vector<ll> (n+1, 0));
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) sum[i] = sum[i-1] + a[i];
    for (int i=0;i<=n;i++) f[i][1] = 1;
    for (int j=2;j<=n;j++) {
        vector<int> last(n+1, -1);
        for (int i=j-1;i<=n;i++) {
            int mo = sum[i] % j;
            if (last[mo] != -1) {
                f[i][j] = mod_plus(f[last[mo]][j], f[last[mo]][j-1]);
            }
            last[mo] = i;
        }
    }
    ll ans = 0;
    for (int i=1;i<=n;i++) {
        ans = mod_plus(ans, f[n][i]);
    }
    cout << ans << endl;
}