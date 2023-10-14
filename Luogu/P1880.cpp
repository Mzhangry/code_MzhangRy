// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int inf = 1e9;
vector<int> sum;
int cw (int a, int b) {
    return sum[b] - sum[a-1];
}
int main() {
    int n; cin >> n; sum.resize(n*2+2);
    vector<int> a(n*2+1);
    for (int i=1;i<=n;i++) {cin >> a[i]; a[i+n]=a[i];}
    for (int i=1;i<=n*2;i++) sum[i] = sum[i-1] + a[i];
    vector< vector<int> > mi(2*n+2, vector<int> (2*n+2, inf)), mx(2*n+2, vector<int> (2*n+2, -inf)), s(2*n+2, vector<int> (2*n+2));
    for (int i=1;i<=2*n;i++) mi[i][i] = mx[i][i] = 0, s[i][i] = i;
    for (int len = 2;len <= n; len++) {
        for (int i=1;i<=2*n-len+1;i++) {
            int j = i + len - 1, w = cw(i, j);
            for (int k = s[i][j-1];k<=s[i+1][j];k++) {
                int d = mi[i][k] + mi[k+1][j] + w;
                if (mi[i][j] > d) mi[i][j] = d, s[i][j] = k;
            }
            mx[i][j] = max(mx[i+1][j], mx[i][j-1]) + w;
        }
    }
    int ansi = inf, ansx = -inf;
    for (int i=1;i<=n;i++) {
        int j = i+n-1;
        ansi = min(mi[i][j], ansi);
        ansx = max(mx[i][j], ansx);
    }
    cout << ansi << endl << ansx << endl;
}