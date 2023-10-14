#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
struct NUM {
    ll d;
    int sum_2 = 0, sum_5 = 0;
};
NUM a[205];
int f[205][8020], fx[205][8020];
void cul(NUM& d) {
    while (d.d % 2 == 0) {d.d /= 2; d.sum_2++;}
    while (d.d % 5 == 0) {d.d /= 5; d.sum_5++;}
}
int main() {
    //freopen("A.in", "r", stdin);
    //freopen("A.out", "w", stdout);
    cin >> n >> k;
    for (int i=1;i<=n;i++) cin >> a[i].d;
    for (int i=1;i<=n;i++) cul(a[i]);
    // vector< vector<ll> > f(n+1, vector<ll> (n+1)); // qian i ge / xuan k ge / sum_2 - sum_5 = j
    memset(f, -1, sizeof(f)); memset(fx, -1, sizeof(fx)); f[0][4005] = 0;
    for (int i=1;i<=n;i++) {
        int c = a[i].sum_2 - a[i].sum_5; NUM d = a[i];
        fx[0][4005] = 0;
        for (int k=1;k<=i;k++) {
            for (int j=0;j<=8010;j++) {
                if (i == 2 && k == 1 && j == 4005) {
                    int u = 0;
                }
                int p = min(d.sum_2, d.sum_5);
                if (j - c < 0 || j - c > 8010 || f[k-1][j-c] == -1) {fx[k][j] = f[k][j]; continue;}

                if (c > 0 && j-c-4005 < 0) p = min(d.sum_2, abs(j-c-4005) + d.sum_5);
                else if (c < 0 && j-c-4005 > 0) p = min(j-c-4005 + d.sum_2, d.sum_5);

                fx[k][j] = max(f[k][j], f[k-1][j - c] + p);
                // if (fx[k][j] != -1) cout << "i: " << i << "  j:" << j << "  k:" << k << " = "  << fx[k][j] << endl;
            }
        }
        swap(f, fx);
    }
    int ans = 0;
    for (int i=0;i<=8010;i++) ans = max(ans, f[k][i]);
    cout << ans << endl;
}

