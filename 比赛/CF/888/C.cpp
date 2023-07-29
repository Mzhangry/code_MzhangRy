// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int n, k;
int c[200005];
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i=1;i<=n;i++) cin >> c[i];
        int cnt = 0;
        if (c[1] == c[n]) {
            for (int i=1;i<=n;i++) if (c[i] == c[1]) cnt++;
            if (cnt >= k) cout << "YES" << endl;
            else cout << "NO" << endl;
        } else {
            int st, cnt1 = 0, cnt2 = 0;
            for (int i=1;i<=n;i++) {
                if (c[i] == c[1]) cnt1++;
                if (cnt1 == k) {
                    st = i+1; break;
                }
            }
            if (cnt1 < k) {
                cout << "NO" << endl;
                continue;
            }
            for (int i=st;i<=n;i++) if (c[i] == c[n]) cnt2++;
            if (cnt2 >= k) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}