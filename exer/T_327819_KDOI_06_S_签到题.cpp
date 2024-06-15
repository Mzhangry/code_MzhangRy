// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t, id; cin >> t >> id;
    while (t--) {
        int n, q; cin >> n >> q;
        vector<int> a (n+1);
        for (int i=1;i<=n;i++) cin >> a[i];
        while (q--) {
            int l, r; cin >> l >> r;
            cout << (r-l+1) << endl;
        }
    }
}