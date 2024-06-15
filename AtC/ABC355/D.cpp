// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
const int maxn = 5*1e5*2 + 10;
struct Node
{
    int x; bool lr; int id;
    bool operator < (const Node &rhs) const {
        if (x == rhs.x) return lr < rhs.lr;
        return x < rhs.x;
    }
}s[maxn];
int l[maxn], sum[maxn];
int main() {
    cin >> n;
    for (int i=1;i<=n;i++) {
        int l, r;
        cin >> l >> r;
        s[2*i-1] = {l, false, i};
        s[2*i] = {r, true, i};
    }
    sort(s+1, s+2*n+1);
    for (int i=1;i<=2*n;i++) if(!s[i].lr) l[s[i].id] = i;
    int ans = 0;
    for (int i=1;i<=2*n;i++) {
        sum[i] = sum[i-1] + (!s[i].lr);
        if (s[i].lr) ans += sum[i-1] - sum[l[s[i].id]];
    }
    cout << ans << endl;
}