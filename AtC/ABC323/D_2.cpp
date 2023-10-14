// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct P {
    ll first, second;
    const bool operator< (const P d) const {
        return first > d.first;
    }
};
int n;
vector< pair< ll, ll>  > m;
priority_queue< P > add;
int main() {
    cin >> n;
    m.resize(n);
    for (int i=0;i<n;i++) {
        ll s, c; cin >> s >> c; m[i] = {s, c};
    }
    sort (m.begin(), m.end());
    ll ans = 0;
    for (auto& d : m) {
        while (!add.empty() && d.first == add.top().first) {d.second += add.top().second; add.pop();}
        while (!add.empty() && d.first > add.top().first) {
            ll p = add.top().first, f = add.top().second;
            ans += f % 2; add.pop();
            if (f/2 != 0) add.push({p * 2, f / 2});
        }
        ans += d.second % 2;
        if (d.second / 2 != 0) add.push({d.first * 2, d.second/2});
    }
    while (!add.empty()) {
        ll p = add.top().first, f = add.top().second;
        ans += f % 2; add.pop();
        if (f/2 != 0) add.push({p * 2, f / 2});
    }
    cout << ans << endl;
}