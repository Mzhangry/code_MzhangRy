// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

ll n, m, k, h;
ll a[55];
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k >> h;
        for (int i=0;i<n;i++) cin >> a[i];
        sort (a, a+n);
        m--;
        int num = -m;
        int ans = 0;
        for (int i=0;i<n;i++) {
            if (a[i] == h) continue;
            while (h+k*num < a[i]) num++;
            if (num > m) break;
            if (h+k*num == a[i]) ans++;
        }
        cout << ans << endl;
    }
}