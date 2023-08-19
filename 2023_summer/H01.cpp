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
const ll inf = 1e18;

int n;
int main() {
    cin >> n;
    vector<int> d(n+1); vector<ll> c(n+1);
    for (int i=1;i<=n;i++) cin >> c[i] >> d[i];
    ll left = -inf, right = inf;
    for (int i=1;i<=n;i++) {
        if (d[i] == 1) {
            right += c[i-1]; left += c[i-1];
            if (left > -1e8) left = max (1LL*1900, left);
            else left = 1900;
            
        } else {            
            right += c[i-1]; left += c[i-1];
            if (right > 1e8) right = 1899;
            else right = min (right, 1LL*1899);
        }
       // cout << 'i' << i << '-' << c[i] << ' ' << left << ' ' << right << endl;
    }
    right += c[n]; left += c[n];
    if (left > right) cout << "Impossible" << endl;
    else if (right > 1e8) cout << "Infinity" << endl;
    else cout << right << endl;
}