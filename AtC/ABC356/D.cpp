// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;
const int mod = 998244353;
ll dp[100], limdp[100];
int nsize;
void moplus(ll &a, ll b) {
    a = (a + b) % mod;
}
int main() {
    cin >> n >> m;
    for (int i=0;;i++) {
        if (n < (1 << i)) {
            nsize = i;
            break;
        }
    }
    if (m & 1) dp[0] = 1;
    if (n >= 1 && m & 1) limdp[0] = 1;
    for (int i=1;i<nsize;i++) {
        dp[i] = dp[i-1];
        if (m & (1 << i)) moplus(dp[i], (1<<i));

        limdp[i] = limdp[i-1];
        if (m & (1 << i)) {
            moplus(limdp[i], m ^ ((m >> i) << i));
            moplus(limdp[i], dp[i-1]);
        }
    }

    cout << limdp[nsize-1] << endl;
}