// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int x[505], a[505];
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i=2;i<=n;i++) cin >> x[i];
        a[1] = x[2] + 1;
        for (int i=2;i<=n;i++) {
            while (a[i-1] <= x[i]) a[i-1] += a[i-2];
            a[i] = a[i-1] + x[i];
        }
        for (int i=1;i<=n;i++) cout << a[i] << ' ';
        cout << endl;
    }
}