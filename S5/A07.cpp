// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

struct Metal
{
    int m, v;
    double p;
    bool operator< (const Metal t) const {
        return p > t.p;
    }
};
Metal a[105];
int main() {
    int k;
    cin >> k;
    while (k--) {
        double w;
        int s;
        cin >> w >> s;
        for (int i=0;i<s;i++) {
            cin >> a[i].m >> a[i].v;
            a[i].p = a[i].v*1.0 / a[i].m;
        }
        sort(a, a+s);
        double ans = 0;
        int i = 0;
        while (w>0) {
            if (w >= a[i].m) {
                ans += a[i].v;
                w -= a[i].m;
            } else {
                ans += a[i].p * w;
                w = 0;
            }
            i++;
        }
        cout << fixed << setprecision(2) << ans << endl;
    }
}