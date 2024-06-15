#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
const int maxn = 2e5 + 10;
int x[maxn];
ll ans0 = 0;
ll chf[maxn];
void init() {
    for (int i=2;i<=m;i++) {
        int d1 = (x[i] + n - x[i-1]) % n, // shun时针半圈
            d2 = (x[i-1] + n - x[i]) % n; // ni时针半圈
        ans0 += min(d1, d2);
        if (d1 < d2) {
            if (x[i] > x[i-1]) chf[x[i-1]] += d2-d1, chf[(x[i])] -= d2-d1; 
            else chf[0] += d2-d1, chf[x[i-1]] += d2-d1, chf[x[i]] -= d2-d1;
        } else {
            if (x[i-1] > x[i]) chf[x[i]] += d1-d2, chf[(x[i-1])] -= d1-d2;
            else chf[0] += d1-d2, chf[x[i-1]] -= d1-d2, chf[x[i]] += d1-d2;
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i=1;i<=m;i++) cin >> x[i];
    init();
    ll ans = 1e18;
    for (int i=1;i<=n-1;i++) chf[i] += chf[i-1], ans = min(chf[i], ans);
    ans = min(chf[0], ans);
    cout << ans + ans0 << endl;
    
}