// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 10e5 + 10;
int n, k;
int a[maxn], b[maxn];
bool exist[maxn];
int ind[maxn], num[maxn];
int f[maxn];
int ans = 0;
void solve() {
    memset(num, 0, sizeof(num));
    memset(f, 0, sizeof(f));
    for (int i=1;i<=k;i++) num[i] = ind[b[i]];
    for (int i=k+1;i<=2*k;i++) num[i] = num[i-k];
    for (int i=1;i<=2*k;i++) if (num[i] && i - num[i] + 1 >= 1) {
        f[i-num[i]+1] ++;
    }
    for (int i=1;i<=2*k;i++) ans = max(ans, f[i]);
}
int main() {
    cin >> n >> k;
    for (int i=1;i<=k;i++) cin >> a[i], ind[a[i]] = i;
    for (int i=1;i<=k;i++) cin >> b[i];
    for (int i=1;i<=k;i++) exist[a[i]] = exist[b[i]] = true;
    solve();
    reverse (b+1, b+1+k);
    solve();
    for (int i=1;i<=n;i++) if (!exist[i]) ans++;
    cout << ans << endl;
}