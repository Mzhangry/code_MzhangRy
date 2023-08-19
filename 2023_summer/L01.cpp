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
using namespace std;
typedef long long ll;

int main() {
    int n;
    vector<int> c, d;
    cin >> n;
    ll ans = 0, cntb = 0;
    for (int i=0;i<2*n;i++) {
        int s, b; cin >> b >> s;
        ans += max(b, s);
        if (b >= s) {cntb++; c.push_back (b-s);}
        else d.push_back(s-b);
    }
    sort (c.begin(), c.end()); sort (d.begin(), d.end());
    if (cntb > n) {
        for (int i=0;i<cntb-n;i++) ans -= c[i];
    } else {
        for (int i=0;i<n-cntb;i++) ans -= d[i];
    }
    cout << ans << endl;
}