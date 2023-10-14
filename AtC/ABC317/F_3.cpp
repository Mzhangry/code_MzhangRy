// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int f[70][12][12][12][2][2][2][2][2][2];
//   位  a余  b余 c余 --限制--  --为零--
int d[70];
const int mod = 998244353;
ll n, a, b, c;
void moplus (int& a, int b) {
    a = (a+b) % mod;
}
int dfs (int num, int ma, int mb, int mc, bool la, bool lb, bool lc, bool za, bool zb, bool zc) {
    if (num < 0) return (!ma && !mb && !mc) && (!za && !zb && !zc);
    if (f[num][ma][mb][mc][la][lb][lc][za][zb][zc] != -1) return f[num][ma][mb][mc][la][lb][lc][za][zb][zc];
    f[num][ma][mb][mc][la][lb][lc][za][zb][zc] = 0;
    for (int i=0;i<=(la ? d[num] : 1);i++) {
        for (int j=0;j<=(lb ? d[num] : 1);j++) {
            int k = (i ^ j); if (k <= (lc ? d[num] : 1)) {
                moplus (f[num][ma][mb][mc][la][lb][lc][za][zb][zc], 
                    dfs (num-1, ((ma << 1) + i) % a, ((mb << 1) + j) % b, ((mc << 1) + k) % c,
                        la && i == d[num], lb && j == d[num], lc && k == d[num],
                        za && !i, zb && !j, zc && !k)
                );
            }
        }
    }
    return f[num][ma][mb][mc][la][lb][lc][za][zb][zc];
}
int main() {
    cin >> n >> a >> b >> c;
    memset(f, -1, sizeof(f));
    for (int i=0;i<=62;i++) d[i] = (n >> i) & 1;
    cout << dfs (62, 0, 0, 0, 1, 1, 1, 1, 1, 1) << endl;
}