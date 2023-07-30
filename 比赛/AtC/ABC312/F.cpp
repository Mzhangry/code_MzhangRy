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

int n, m;
vector<int> c, y, k;
int f;
ll ans;
ll sumc[200005], sumy[200005], sumk[200005];
void sot (vector<int>& a) {
    sort (a.begin(), a.end(), greater());
}
void sm (vector<int>& a, ll sum[]) {
    for (int i=1;i<=a.size();i++) sum[i] = sum[i-1] + a[i-1];
}
int main() {
    cin >> n >> m;
    for (int i=0;i<n;i++) {
        int t, x; cin >> t >> x;
        if (t == 0) y.push_back(x);
        else if (t == 1) c.push_back(x);
        else k.push_back(x);
        // if (t == 0 || t == 1) z.push_back(x);
    }
    sot(c);sot(y);sot(k);
    sm(c, sumc);sm(y, sumy);sm(k, sumk);
    int numk = 0;
    for (int i=0;i<=min((int)c.size(), m);i++) {
        if (i > sumk[numk]) numk++;
        if (numk > k.size() || numk + i > m) break;
        ans = max(ans, sumc[i] + sumy[min((int)y.size(), m-i-numk)]);
    }
    cout << ans << endl;
}