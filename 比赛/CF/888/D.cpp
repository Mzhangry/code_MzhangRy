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

int n;
ll sum[200005];
bool a[200005];
ll extra;
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n;
        memset (sum, 0, sizeof (sum));
        memset (a, 0, sizeof(a));
        extra = -1;
        for (int i=1;i<n;i++) cin >> sum[i];
        bool flag = false;
        for (int i=1;i<n;i++) {
            ll num = sum[i] - sum[i-1];
            if (num > n || num <= 0 || a[num]) {
                if (extra >= 0) {
                    cout << "NO" << endl;
                    flag = true;
                    break;
                }
                extra = num;
            }
            else a[num] = true;
        }
        if (flag) continue;
        vector<ll> mis;
        for (int i=1;i<=n;i++) {
            if (!a[i]) mis.push_back(i);
        }
        if (mis.size() == 1) {cout << "YES" << endl; continue;}
        else if (mis.size() == 2) {
            if (mis[0] + mis[1] == extra) cout << "YES" << endl;
            else cout << "NO" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}