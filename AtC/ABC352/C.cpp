// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
const int maxn = 2e5 + 10;
ll a[maxn], b[maxn];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    ll maxh = -1;
    for (int i=0;i<n;i++) maxh = max(maxh, b[i] - a[i]);
    ll sum = 0;
    for (int i=0;i<n;i++) sum += a[i];
    cout << sum + maxh << endl;
}