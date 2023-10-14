// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, d, p; cin >> n >> d >> p;
    vector<int> a(n+1);
    for (int i=1;i<=n;i++) cin >> a[i];
    sort(a.begin()+1, a.end(), greater<int>());
    vector<ll> f(n+1);
    for (int i=1;i<=n;i++) f[i] = min(f[i-1] + a[i], p + (i - d <= 0 ? 0 : f[i-d]));
    cout << f[n] << endl;
}