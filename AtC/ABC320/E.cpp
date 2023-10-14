// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
int main() {
    cin >> n >> m;
    set < pair<ll, int> > back; // time num
    vector< ll > ans(n+1);
    set <int> exist;
    for (int i=1;i<=n;i++) exist.insert(i);
    while (m--) {
        ll t, w, s; cin >> t >> w >> s;
        
        int cnt = 0;
        for (auto d : back) {
            if (d.first <= t) {
                exist.insert(d.second);
                cnt++;
            } else {
                break;
            }
        }
        for (int i=0;i<cnt;i++) back.erase(back.begin());
        if (exist.empty()) continue;
        int add = *exist.begin();
        ans[add] += w;
        back.insert({t + s, add});
        exist.erase(exist.begin());
    }
    for (int i=1;i<=n;i++) cout << ans[i] << endl;
}