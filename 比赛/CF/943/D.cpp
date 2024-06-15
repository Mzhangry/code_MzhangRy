// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;
int pb, ps;
int main() {
    int t; cin >> t; while (t--) {
        cin >> n >> k >> pb >> ps;
        vector<ll> p(n+5), a(n+5);
        for (int i=1;i<=n;i++) cin >> p[i];
        for (int i=1;i<=n;i++) cin >> a[i];
        ll mxB = a[pb] * k, mxS = a[ps] * k;
        ll sumB=0, sumS=0;
        for (int i=1;i<=min(n, k);i++) {
            sumB += a[pb], sumS += a[ps];
            pb = p[pb], ps = p[ps];
            mxB = max(mxB, sumB + a[pb] * (k-i)),
            mxS = max(mxS, sumS + a[ps] * (k-i));
        }
        if (mxB > mxS) cout << "Bodya" << endl;
        else if (mxB < mxS) cout << "Sasha" << endl;
        else cout << "Draw" << endl;
    }
}