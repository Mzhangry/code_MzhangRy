// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    vector<ll> f(1 << n);
    vector< vector<ll> > d(n+1, vector<ll> (n+1));
    for (int i=0;i<=n;i++) for (int j=i+1;j<n;j++) cin >> d[i][j];
    for (int S = 1; S < (1 << n); S++) {
        int x = __builtin_ctz(S);
        f[S] = f[S ^ (1 << x)];
        for (int i=x+1;i<n;i++) {
            if (S & (1 << i)) {
                f[S] = max(f[S], f[S ^ (1<<x) ^ (1<<i)] + d[x][i]);
            }
        }
    }
    cout << f[(1<<n) - 1] << endl;
}