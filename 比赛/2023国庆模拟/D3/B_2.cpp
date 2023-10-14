// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<int> a;
const double inf = 1e-6;

bool ok (double num) {
    vector<double> b(n+1);
    double sum = 0, mx = 0, cur = 0;
    for (int i=1;i<=n;i++) b[i] = a[i] - num, sum += b[i];
    for (int i=2;i<=n-1;i++) {cur = max (cur + b[i], b[i]); mx = max(mx, cur);}
    return sum - mx <= 0;
}

int main() {
    cin >> n;
    a.resize(n+1);
    for (int i=1;i<=n;i++) cin >> a[i];
    double l = 1, r = 2e9, mid;
    while (r - l > inf) {
        mid = l + (r - l) / 2.0;
        if (ok (mid)) r = mid;
        else l = mid;
    }
    cout << fixed << setprecision(2) << l << endl;
}