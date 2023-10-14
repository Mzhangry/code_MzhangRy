// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

unordered_map<int, vector<ll> > m;
int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;i++) {
        cin >> a[i];
        m[a[i]].push_back(i);
    }
    ll ans = 0;
    for (auto point : m) {
        vector<ll> v = point.second;
        if (v.size() < 2) continue;
        // sort(v.begin(), v.end());
        for (int i=0;i<v.size();i++) {
            ans += (v[i] - 1)*(i) - (v[i])*(v.size() - i - 1);
        }
        for (int i=1;i<v.size()-1;i++) ans -= i*(v.size()-1-i);
    }
    cout << ans << endl;
}