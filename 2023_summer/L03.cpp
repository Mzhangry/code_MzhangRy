// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<unordered_map>
using namespace std;
typedef long long ll;

int n;
unordered_map<ll, int> s;
ll need (ll a) {
    ll d = 0;
    bool add = false;
    int first;
    for (int i=32;i>=0;i--) if ((a >> i) & 1) {
        first = i; break;
    }
    for (int i=0;i<=first;i++) {
        int w = ((a >> i) & 1) + add;
        if (w > 0) add = true;
        else add = false;
        if (w == 1) d |= (1 << i);
    }
    return d;
}
int main() {
    // freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i=0;i<n;i++) {
        ll a; cin >> a;
        s[a]++;
    }
    ll cnt = 0, ans = 0;
    for (auto d : s) {
        ll ne = need (d.first);
        if (s.find(ne) == s.end()) continue;
        int num = s[ne];
        if (ne == d.first) {num--; cnt += 1LL*num*d.second;}
        ans += 1LL*num*d.second;
        // cout << d.first << ' ' << need(d.first) << endl;
    }
    cout << ans - cnt/2 << endl;
}