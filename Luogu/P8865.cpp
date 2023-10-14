// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

ll n, m, c, f;
void moplusc (int& a, ll b) {
    a = ((a + b) * c) % mod;
}
void moplusf (int& a, ll b) {
    a = ((a + b) * f) % mod;
}
int main() {
    ios::sync_with_stdio(false);
    int t, id; cin >> t >> id;
    while (t--) {
        cin >> n >> m >> c >> f;
        vector< vector<int> > e(n+2, vector<int> (m+2)), f1(n+2, vector<int> (m+2)), fc(n+2, vector<int> (m+2)), sum(n+2, vector<int> (m+2)), ff(n+2, vector<int> (m+2)), cnts(n+2, vector<int> (m+2));
        for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) {char c; cin >> c; e[i][j] = c - '0';}
        for (int i=1;i<=n;i++) for (int j=m;j>=1;j--) if (!e[i][j]) f1[i][j] = f1[i][j+1] + 1;
        for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) if (!e[i][j]) sum[i][j] = sum[i-1][j] + f1[i][j] - 1;
        for (int j=1;j<=m;j++) for (int i=n;i>=1;i--) if (!e[i][j]) cnts[i][j] = cnts[i+1][j] + 1;
        for (int i=3;i<=n;i++) for (int j=1;j<=m;j++) {
            if (!e[i][j] && !e[i-1][j]) moplusc (fc[i][j], sum[i-2][j] * (f1[i][j] - 1));
            if (!e[i][j] && !e[i-1][j]) moplusf (ff[i][j], sum[i-2][j] * (f1[i][j] - 1) % mod * cnts[i+1][j]);
        }
        int ansc = 0, ansf = 0;
        for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) {
            moplusc (ansc, fc[i][j]); moplusf(ansf, ff[i][j]);
        }
        cout << ansc << ' ' << ansf << endl;
    }
}