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
vector<int> s, d;
int find_set (int a) {
    if (s[a] != a) {
        int t = s[a];
        s[a] = find_set (s[a]);
        d[a] += d[t];
    }
    return s[a];
}
ll ans = 0;
void merge_set (int a, int b, int v) {
    int sa = find_set(a), sb = find_set(b);
    if (sa == sb && d[a] - d[b] != v) ans++;
    else {
        s[sa] = sb;
        d[sa] = v + d[b] - d[a];
    }
}
int main() {
    cin >> n >> m;
    s.resize(n+1); d.resize(n+1);
    for (int i=0;i<=n;i++) s[i] = i;
    while (m--) {
        int a, b, v; cin >> a >> b >> v;
        merge_set (a, b, v);
    }
    cout << ans << endl;
}