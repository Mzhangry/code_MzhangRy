// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int g, n;
int xd[100005], yd[100005], td[100005];
int xc[100005], yc[100005], tc[100005];
double lenab (long long x1, long long y1, long long x2, long long y2) {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
int main() {
    cin >> g >> n;
    for (int i=1;i<=g;i++) cin >> xd[i] >> yd[i] >> td[i];
    for (int i=1;i<=n;i++) cin >> xc[i] >> yc[i] >> tc[i];

    int ans = 0;
    for (int i=1;i<=n;i++) {
        bool flag = true;
        for (int j=1;j<=g;j++) {
            int t = abs(td[j] - tc[i]);
            if (lenab(xd[j], yd[j], xc[i], yc[i]) <= t) {
                 cout << i  << ' '<< j  << ' ' << lenab(xd[j], yd[j], xc[i], yc[i]) << ' ' << t << endl;
                flag = false;
                break;
            }
        }
        if (flag) ans++;
    }
    cout << ans;
}