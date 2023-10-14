// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
unordered_map<ll, ll> m, ma;
int main() {
    cin >> n;
    for (int i=0;i<n;i++) {
        int s, c; cin >> s >> c; m[s] = c;
    }
    while (1) {
        bool flag = false;
        for (auto& d : m) {
            if (d.second/2 > 0) ma[d.first*2] += d.second/2, flag = true;
            d.second %= 2;
        }
        if (!flag) break;
        for (auto d : ma) {
            m[d.first] += d.second;
        }
        ma.clear();
    }
    int cnt = 0;
    for (auto d : m) cnt += d.second;
    cout << cnt << endl;
}