// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e5 + 10;
int a[maxn], st[maxn], ed[maxn];
int main() {
    int n; cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) {
        st[i] = min(a[i], st[i-1] + 1);
    }
    for (int i=n;i>=1;i--) {
        ed[i] = min(a[i], ed[i+1] + 1);
    }
    int ans = 0;
    for (int i=1;i<=n;i++) ans = max(ans, min(st[i], ed[i]));
    cout << ans << endl;
}