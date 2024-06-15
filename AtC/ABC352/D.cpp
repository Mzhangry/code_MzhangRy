// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e5 + 10;
multiset<int> s;
int ind[maxn];
int main() {
    int n, k; cin >> n >> k;
    for (int i=1;i<=n;i++) {
        int a; cin >> a;
        ind[a] = i;
    }
    for (int i=1;i<=k;i++) s.insert(ind[i]);
    int ans = *s.rbegin() - *s.begin();
    for (int i=k+1;i<=n;i++) {
        s.erase(s.find(ind[i-k]));
        s.insert(ind[i]);
        ans = min(ans, *s.rbegin() - *s.begin());
    }
    cout << ans << endl;
}