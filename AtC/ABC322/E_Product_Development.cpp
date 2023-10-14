// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k, p;
const ll inf = 1e15;
int get_bits (int a = 0, int b = 0, int c = 0, int d = 0, int e = 0) {
    return a + (b << 3) + (c << 6) + (d << 9) + (e << 12);
}
int main() {
    cin >> n >> k >> p;
    vector<ll> cost(n+1);
    vector< vector<int> > s(n+1, vector<int> (5+1));
    for (int i=1;i<=n;i++) {
        cin >> cost[i];
        for (int j=1;j<=k;j++) {
            cin >> s[i][j];
        }
    }
    vector<ll> f (1 << 16, inf);
    f[0] = 0;
    for (int i=1;i<=n;i++) {
        for (int a = p; a >= 0; a--) {
            for (int b = (k>=2 ? p : 0); b >= 0 ;b--) {
                for (int c = (k >= 3 ? p : 0); c >= 0; c--) {
                    for (int d = (k >= 4 ? p : 0); d >= 0 ;d--) {
                        for (int e = (k == 5 ? p : 0); e >= 0; e--) {
                            int aa = min (p, a + s[i][1]),
                                bb = min (p, b + s[i][2]),
                                cc = min (p, c + s[i][3]),
                                dd = min (p, d + s[i][4]),
                                ee = min (p, e + s[i][5]);
                            f[get_bits(aa, bb, cc, dd, ee)] = min (f[get_bits(aa, bb, cc, dd, ee)], f[get_bits(a, b, c, d, e)] + cost[i]);
                        }
                    }
                }
            }
        }
    }
    cout << (f[get_bits(p, k >= 2 ? p : 0, k >= 3 ? p : 0, k >= 4 ? p : 0, k == 5 ? p : 0)] >= inf ? -1 : f[get_bits(p, k >= 2 ? p : 0, k >= 3 ? p : 0, k >= 4 ? p : 0, k == 5 ? p : 0)])  << endl;
}