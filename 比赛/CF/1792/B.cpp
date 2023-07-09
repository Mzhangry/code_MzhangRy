// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int t;
int main() {
    //freopen("B.in", "r", stdin);
    //freopen("B.out", "w", stdout);
    cin >> t;
    while (t--) {
        int a1, a2, a3, a4;
        cin >> a1 >> a2 >> a3 >> a4;
        if (a1 == 0) {
            cout << 1 << endl;
            continue;
        }
        int ans = a1;
        ans += min(a2, a3) * 2;
        int m = min(a2, a3);
        a2 -= m;
        a3 -= m;
        ans += min(max(a2, a3), a1);
        int d = a1 - min(max(a2, a3), a1);
        if (a2 == 0) a3 -= min(a3, a1);
        else a2 -= min(a2, a1);
        ans += min(d, a4);
        a4 -= min(d, a4);
        if (a2 | a3 | a4) ans++;
        cout << ans << endl;
    }
}