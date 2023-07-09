// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

struct Cow
{
    long long v, p; // v, value  p, old pos
    const bool operator < (const Cow d) const {
        return v < d.v;
    }
};
Cow c[150005];
long long sum[150005];
long long pos[150005];
long long ans = 0;

int main() {
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) {
        cin >> c[i].v;
        c[i].p = i;
    }
    sort (c+1, c+n+1);
    for (int i=1;i<=n;i++) {
        ans += c[i].v * i;
        sum[i] = sum[i-1] + c[i].v;
        pos[c[i].p] = i;
    }
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        long long ans1 = ans;
        long long pp = lower_bound (c+1, c+n+1, (Cow){y,0}) - c;
        // cout << pp << ' ';
        if (pp > pos[x]) ans1 = ans1 - (sum[pp-1] - sum[pos[x]])  - pos[x] * c[pos[x]].v + (pp-1) * y;
        else ans1 = ans1 + sum[pos[x] - 1] - sum[pp-1]  - pos[x] * c[pos[x]].v + pp * y;
        cout << ans1 << endl;
    }
}