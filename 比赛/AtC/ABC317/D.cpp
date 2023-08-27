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
const ll inf = 1e12;

struct Zone
{
    ll x, y, z;
};
vector<Zone> e;

int allz, xm;
int main() {
    int n; cin >> n;
    //e.push_back({-1, -1, -1});
    for (int i=0;i<n;i++) {
        ll x, y, z; cin >> x >> y >> z;
        allz += z;
        if (x > y) {
            xm += z;
        } else {
            e.push_back ({x, y, z});
        }
    }
    if (xm > allz / 2) {
        cout << 0 << endl;
        return 0;
    }
    vector<ll> f(allz+1, inf);
    f[0] = 0;
    for (int i=0;i<e.size();i++) {
        for (int j=allz;j-e[i].z >= 0;j--) {
            f[j] = min (f[j-e[i].z] + ((e[i].y - e[i].x) / 2 + 1), f[j]);
        }
    }
    int need = max(0, (allz - 2*xm) / 2 + 1);
    ll ans = inf;
    for (int i=need;i<=allz;i++) {
        ans = min(ans, f[i]);
    }
    cout << ans << endl;
}