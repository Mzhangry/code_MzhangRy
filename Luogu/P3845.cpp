// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<P> a(n+1);
        vector<bool> vis(n+1);
        for (int i=1;i<=n;i++) {
            cin >> a[i].first >> a[i].second;
            if (a[i].first > a[i].second) swap(a[i].first, a[i].second);
        }
        int cnt = 0, ans = 0;
        while (cnt < n) {
            for (int i=1;i<=n;i++) if (!vis[i]) {
                vis[i] = true; ans ++; cnt++;
                for (int j=i+1;j<=n;j++) if (!vis[j]) {
                    if (a[i].first >= a[j].first && a[i].second >= a[i].second || a[i].first <= a[j].first && a[i].second <= a[j].second) {
                        cnt++; vis[j] = true;
                    }
                }
            }
        }
        cout << ans << endl;
    }
}