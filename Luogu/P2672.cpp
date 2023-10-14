// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int n;
int main() {
    cin >> n;
    vector<int> sum(n+1), fmx(n+1), tmx(n+1+1);
    vector<P> h(n+1); // <a, s>
    for (int i=1;i<=n;i++) cin >> h[i].second;
    for (int i=1;i<=n;i++) cin >> h[i].first;
    sort (h.begin()+1, h.end());
    reverse (h.begin()+1, h.end());
    for (int i=1;i<=n;i++) sum[i] = sum[i-1] + h[i].first;
    for (int i=1;i<=n;i++) fmx[i] = max(fmx[i-1], 2*h[i].second);
    for (int i=n;i>=1;i--) tmx[i] = max(tmx[i+1], 2*h[i].second + h[i].first);
    for (int i=1;i<=n;i++) cout << max(sum[i] + fmx[i], sum[i-1] + tmx[i+1]) << endl;
}