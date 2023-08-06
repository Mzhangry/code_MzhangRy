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
    vector<int> d(n); vector<ll> c(n);
    for (int i=0;i<n;i++) cin >> c[i] >> d[i];
    ll left = -inf, right = inf;
    for (int i=0;i<n;i++) {
        if (d[i] == 1) {
            if (left > -1e8) left = min (1LL*1900, left);
            else left = 1900;
            right += c[i]; left += c[i];
            
        } else {
            if (right > 1e8) right = 1899;
            else right = max (right, 1LL*1899);
            right += c[i]; left += c[i];
        }
        cout << 'i' << i << '-' << c[i] << ' ' << left << ' ' << right << endl;
    }
    if (left > right) cout << "Impossible" << endl;
    else if (right > 1e8) cout << "Infinity" << endl;
    else cout << right << endl;
}