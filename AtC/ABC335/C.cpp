// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, q;
int main() {
    cin >> n >> q;
    vector<int> x(q+10), y(q+10);
    int cnt = 0; x[0] = 1, y[0] = 0;
    while (q--) {
        int a, b; char c; cin >> a;
        if (a == 1) {
            cin >> c; cnt++;
            if (c == 'R') {
                x[cnt] = x[cnt-1] + 1;
                y[cnt] = y[cnt-1];
            } else if (c == 'L') {
                x[cnt] = x[cnt-1] - 1;
                y[cnt] = y[cnt-1];
            } else if (c == 'U') {
                x[cnt] = x[cnt-1];
                y[cnt] = y[cnt-1] + 1;
            } else if (c == 'D') {
                x[cnt] = x[cnt-1];
                y[cnt] = y[cnt-1] - 1;
            }
        } else {
            cin >> b; int t = cnt - b + 1;
            if (t >= 0) cout << x[t] << ' ' << y[t] << endl;
            else cout << -t + 1 << ' ' << 0 << endl;
        }
    }
}