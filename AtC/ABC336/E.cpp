// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f[150][150][2][2]; // 0 限制
int s[20];
ll solve (int d, int num, int mod, bool z, bool limit) {
    if (f[num][mod][z][limit] >= 0) return f[num][mod][z][limit];
    int t = limit ? s[d] : 9;
    ll ans = 0;
    for (int i=0;i<=t;i++) { // select
        if (i == 0) 
        else ans += solve (d-1, num, (10 * mod - i) % mod, false, limit && (i == t)) + 
                    solve (d-1, num, (10 * mod - i) % mod, true, limit && (i == t));
    }
}
int main() {
    ll n; cin >> n;
    for (int i=0;i<=128;i++) f[0][i] = 1;
    
}