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

ll a, b;
const int maxn = 1e9;
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> a >> b;
        ll left = 1, right = maxn, mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (a <= mid * mid) right = mid;
            else left = mid + 1;
        }
        ll pf1 = right; // 大于等于a的pf前的num
        left = 1, right = maxn;
        while (left < right) {
            mid = (left + right) / 2;
            if (b <= mid * mid) right = mid;
            else left = mid + 1;
        }
        ll pf2 = right;
        if (pf2 * pf2 != b) pf2--;
        ll ans = 0;
        ans += (pf2 - pf1) * 3;
        if (a != pf1 * pf1) ans++;
        if (a <= (pf1 * pf1) - 1 - (pf1 - 1)) ans++;
        ans++;
        if (b >= pf2 * pf2 + pf2) ans++;
        if (b >= pf2 * pf2 + 2*pf2) ans++;
        cout << ans << endl;
    }
}