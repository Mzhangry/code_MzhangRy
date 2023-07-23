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

const int inf = 1e9;
int n, m;
int a[1005];
int f[1005];
bool ok (ll num) {
    for (int i=0;i<=n;i++) f[i] = inf;
    f[2] = 1; f[0] = f[1] = 0;
    // if (num == 0) f[0] = f[1] = 0;
    for (int i=2;i<=n;i++) {
        for (int j=i-1;i-j-1 <= m;j--) {
            if (j == 0) a[0] = a[i];
            if (f[j] != inf && abs(a[i] - a[j]) <= (i-j) * num) {
                f[i] = min (f[i], f[j] + i-j-1);
            }
        }
    }
    int ans = inf;
    for (int i=0;i<=n;i++) {
        if (f[i] != inf) ans = min(ans, f[i] + n-i);
    }
    if (ans == inf || ans > m) return false;
    return true;
}
int main() {
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i];
    int left = 0, right = 2e9;
    ll mid;
    while (right > left) {
        mid = ((ll)right + left) / 2;
        if (ok(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << right << endl;
}