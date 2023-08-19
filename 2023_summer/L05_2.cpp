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
struct Point {
    int p; char c;
};
int n;
int main() {
    cin >> n;
    vector<Point> e(n);
    for (int i=0;i<n;i++) {
        cin >> e[i].p >> e[i].c;
    }
    ll ans = 0; int left = -1, right = -1;
    ll lastr = -1, lastb = -1, maxcR = -1, maxcB = -1;
    ll firr = 1e10, firb = 1e10;
    for (auto d : e) {
        if (d.c == 'R' && firr == 1e10) firr = d.p;
        else if (d.c == 'B' && firb == 1e10) firb = d.p;
    }
    if (firr == 1e10 || firb == 1e10) { // 只有一种颜色 ans = 整条链接
        cout << e[n-1].p - e[0].p << endl; return 0;
    }
    for (auto d : e) {
        if (d.c == 'G') {
            if (right == -1) {
                right = d.p;
                if (firr < right) ans += right - firr;
                if (firb < right) ans += right - firb;
            } else {
                left = right;
                right = d.p;
                if (lastr != left) maxcR = max(maxcR, d.p - lastr);
                if (lastb != left) maxcB = max(maxcB, d.p - lastb);
                ll t = 1e10, d = right - left;
                if (lastr == left && lastb == left) t = d;
                else if (lastr == left || lastb == left) {
                    t = 2*d - max(maxcB, maxcR);
                } else {
                    t = 3*d - maxcB - maxcR;
                    t = min(2*d, t);
                }
                ans += t;
            }
            lastr = right, lastb = right, maxcR = -1, maxcB = -1;
        } else if (d.c == 'R') {
            maxcR = max(maxcR, d.p - lastr);
            lastr = d.p;
        } else {
            maxcB = max(maxcB, d.p - lastb);
            lastb = d.p;
        }
    }
    if (right == -1) {
        cout << (lastb - firb) + (lastr - firr) << endl;
        return 0;
    }
    if (lastb > right) ans += lastb - right;
    if (lastr > right) ans += lastr - right;
    cout << ans << endl;
}