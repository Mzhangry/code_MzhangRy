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
struct Operate
{
    char op;
    int l, r;
    ll tim;
};
const int mod = 1e9 + 7;

Operate e[200005];
int n, m;
ll a[200005], opcf[200005];
ll fastpower (ll a, ll b) {
    if (b == 0) return 1;
    ll ans = fastpower (a, b/2);
    ans = ans * ans % mod;
    if (b % 2 == 1) ans = ans * a % mod;
    return ans;
}
int main() {
    cin >> n >> m;
    for (int i=1;i<=m;i++) {
        char c; int a, b; cin >> c >> a >> b;
        e[i] = {c, a, b, (ll)1};
    }

    for (int i=1;i<=m;i++) opcf[i] = 0; // 计算查分操作次数数组
    ll tt = 0;
    for (int i=m;i>=1;i--) {
        Operate d = e[i];
        tt = opcf[i];
        if (d.op == '*') {
            opcf[d.r] = (opcf[d.r] + fastpower(2, tt)) % mod;
            opcf[d.l-1] = (opcf[d.l-1] - fastpower(2, tt)) % mod;
        }
    }
    ll times = 0;
    for (int i=m;i>=1;i++) {
        //times += opcf[i];
        if (e[i].op == '+') e[i].tim = fastpower(2, opcf[i]);
    }

    for (int i=n;i>=1;i--) {
        Operate d = e[i];
        if (d.op == '+') {
            a[d.l] = (a[d.l] + d.tim) % mod;
            a[d.r+1] = (a[d.r+1] - d.tim) % mod;
        } 
    }
    for (int i=1;i<=n;i++) {
        a[i] = a[i-1] + a[i];
        cout << a[i] << endl;
    }
}