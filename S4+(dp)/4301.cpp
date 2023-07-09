// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int t, n;
int a[200005];
bool f[200005];
int main() {
    cin >> t;
    f[0] = 1;
    while (t--) {
        cin >> n;
        for (int i=1;i<=n;i++) f[i] = false;
        for (int i=1;i<=n;i++) cin >> a[i];
        for (int i=1;i<=n;i++) {
            if (i + a[i] <= n && f[i-1]) f[i+a[i]] = true;
            if (i - a[i] >= 0 && f[i-a[i]-1]) f[i] = true;
        }
        if (f[n]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}