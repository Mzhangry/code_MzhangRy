// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const int inf = 1e9;

int n;
double a[20][20];
double f[1<<20];
int main() {
    cin >> n;
    for (int i=0;i<n;i++) for (int j=0;j<n;j++) cin >> a[i][j];
    f[(1<<n) - 1] = 1;
    for (int S = (1<<n)-1;S>=1;S--) {
        int w =  __builtin_popcount(S);
        if (w<2) continue;
        int num = w * (w - 1) / 2;
        for (int i=0;i<n;i++) {
            if (S >> i & 1) {
                for (int j=0;j<n;j++) {
                    if ((S^(1<<i)) >> j & 1) {
                        f[S^(1<<j)] += 1.0 / num * a[i][j] * f[S];
                    }
                }
            }
        }
    }
    for (int i=0;i<n;i++) {
        cout << fixed << setprecision(6) << f[1<<i] << ' ';
    }
    cout << endl;
}