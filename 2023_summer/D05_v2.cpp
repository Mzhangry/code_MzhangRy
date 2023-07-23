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
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

map<ll, int> m;
set<P> point;
int n;
P e[2005];
ll dis (P a, P b) {
    return (ll)(b.first - a.first) * (b.first - a.first) + (ll)(b.second - a.second) * (b.second - a.second);
}
bool inl (P a, P d) {
    return point.count({2 * d.first - a.first, 2 * d.second - a.second});
}
int cnt_inline = 0;
ll ans = 0;
int main() {
    cin >> n;
    for (int i=1;i<=n;i++) {
        int a, b; cin >> a >> b;
        e[i] = make_pair(a, b);
        point.insert(make_pair(a, b));
    }
    for (int i=1;i<=n;i++) {
        m.clear();
        for (int j=1;j<=n;j++) if (! (i == j)) {
            if (inl(e[j], e[i])) cnt_inline++;
            m[dis (e[i], e[j])] ++;
        }
        for (auto p : m) {
            if (p.second > 1) {
                ans += p.second * (p.second - 1);
            }
        }
    }
    cout << (ans - cnt_inline) / 2 << endl;
}