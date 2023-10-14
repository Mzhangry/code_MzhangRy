#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<ll> a, sum;
const int inf = 2e9+10;

double d_erase (int st, int ed) {
    return (sum[n] - sum[ed] + sum[st-1])*1.0 / (n - (ed - st + 1));
}
double cul(int st) {

    int l = st, r = n-1, mid;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (d_erase(st, mid) > d_erase(st, mid+1)) l = mid+1;
        else r = mid;
    }
    return d_erase(st, l);
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    a.resize(n+1); sum.resize(n+1);
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) sum[i] = sum[i-1] + a[i];

    double ans = (sum[n]* 1.0) / n;
    for (int st=2;st<=n-1;st++) {
        for (int ed = st; ed <= n-1; ed++) 
            ans = min(ans, d_erase(st, ed));
    }
    cout << fixed << setprecision(2) << ans;
}

