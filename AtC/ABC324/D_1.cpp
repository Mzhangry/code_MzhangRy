// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<int> sx;
int n; vector<int> a;
vector<ll> mul(20);
void init() {
    mul[0] = 1;
    for (int i=1;i<=15;i++) mul[i] = mul[i-1] * 10;
}
bool cul() {
    ll sum = 0;
    for (int i=0;i<=n;i++) {
        sum += a[sx[i]] * mul[i];
    }
    if (sum == (int)sqrt(sum) * (int)sqrt(sum)) {for (int d:sx) cout << d << ' ' ; cout << endl;  return true;}
    return false;
}
int ans = 0;
vector<bool> vis;
void dfs (int d) {
    if (d == n) {
        if (cul()) ans++;
    }
    for (int i=0;i<n;i++) if (!vis[i]) {
        vis[i] = true; sx[d] = i;
        dfs(d+1);
        vis[i] = false;
    }
}
int main() {
    init();
    cin >> n; sx.resize(n); vis.resize(n);
    char c; c = getchar();
    for (int i=0;i<n;i++) {
        c = getchar();
        a.push_back(c - '0');
    }
    sort(a.begin(), a.end());
    n = unique(a.begin(), a.end()) - a.begin();
    dfs(0);
    cout << ans << endl;
}