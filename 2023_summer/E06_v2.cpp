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
ll a[200005], mul[200005];

int main() {
    cin >> n >> m;
    for (int i=1;i<=m;i++) {
        char c; int a, b; cin >> c >> a >> b;
        e[i] = {c, a, b, (ll)1};
    }

    ll times = 1;
    for (int i=m;i>=1;i--) {
        times = (times + mul[i]) % mod;

        Operate& d = e[i];
        if (d.op == '*') {
            mul[d.r] = (mul[d.r] + times) % mod;
            mul[d.l-1] = (mul[d.l-1] - times) % mod;
        }
        if (d.op == '+') d.tim = times;
    }

    for (int i=m;i>=1;i--) {
        Operate& d = e[i];
        if (d.op == '+') {
            a[d.l] = (a[d.l] + d.tim) % mod;
            a[d.r+1] = (a[d.r+1] - d.tim) % mod;
        } 
    }
    for (int i=1;i<=n;i++) {
        a[i] = (a[i-1] + a[i] + mod) % mod;
        cout << a[i] << endl;
    }
}