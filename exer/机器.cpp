#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;

struct P {
    ll x, y; int t;
    const bool operator< (const P d) const {
        return x == d.x ? (y == d.y ? t < d.t  : y < d.y) : x < d.x;
    }
};
int n;
map<P, int> cnt;
int main() {
    cin >> n;
    P ed; cin >> ed.x >> ed.y;
    cnt[{0, 0, 0}] = 1;
    for (int i=0;i<n;i++) {
        int a, b; cin >> a >> b;
        map<P, int> tmp;
        for (auto d : cnt) {
            tmp[d.first] = d.second;
        }
        for (auto d : tmp) {
            cnt[{d.first.x + a, d.first.y + b, d.first.t + 1}] += d.second;
        }

    }
    for (int i=1;i<=n;i++) cout << cnt[{ed.x, ed.y, i}] << endl;
}
