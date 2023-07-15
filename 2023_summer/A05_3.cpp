// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int n;
int a[500005];
long long ok[500005];

bool solve (int s=0, int cs=0, int b=0, int cb=0, int pos = 0) {
    if (pos > n) return true;
    if (a[pos] - s != cs) { // 只能接在b中
        if (cb && a[pos] - b != cb) return false; // b也不行
        if (b == 0) return solve (s, cs, a[pos], 0, pos+1);
        else if (cb == 0) return solve (s, cs, a[pos], a[pos]-b, pos+1);
        else return solve (s, cs, a[pos], cb, pos+1);
    } else { // 可以接在a中
        // 接a
        if (solve (a[pos], cs, b, cb, pos+1)) return true;
        // 不接
        if (b == 0) return ok[pos];
        else if (cb == 0) return ok[pos] && a[pos] - b == a[n] - a[n-1];
        else return ok[pos] && cb == a[n] - a[n-1] && a[pos] - b == a[n] - a[n-1];
    }
    return false;
}
int main() {
    int t; cin >> t;
    while (t--) {
        memset (ok, 0, sizeof(ok));
        cin >> n;
        for (int i=1;i<=n;i++) cin >> a[i];
        ok[n] = ok[n-1] = true;
        for (int i=n-2;i>=1;i--) if (ok[i+1] && a[i+1] - a[i] == a[n] - a[n-1]) ok[i] = true;
        if (solve(a[2], a[2]-a[1], 0, 0, 3) | solve(a[3], a[3]-a[2], a[1], 0, 4) | solve(a[3], a[3]-a[1], a[2], 0, 4)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}