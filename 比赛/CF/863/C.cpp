// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int t;
int a[200005], b[200005];
int main() {
    // freopen ("c.out", "w", stdout);
    cin >> t;
    while (t--) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        int n;
        cin >> n;
        for (int i=1;i<=n-1;i++) cin >> b[i];
        a[1] = b[1];
        for (int i=2;i<=n-1;i++) a[i] = min(b[i-1], b[i]);
        a[n] = b[n-1];
        for (int i=1;i<=n;i++) cout << a[i] << ' ';
        cout << endl;
    }
    return 0;
}