// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;
void moplus (int& a, int b) {
    a = (a + b) % mod;
}
int main() {
    int q, k; cin >> q >> k;
    vector<int> f(k+1);
    f[0] = 1;
    while (q--) {
        char c; int d; cin >> c >> d;
        
        if (c == '+') for (int i=k;i>=d;i--) moplus (f[i], f[i-d]);
        else for (int i=d;i<=k;i++) moplus (f[i], mod-f[i-d]);
        cout << f[k] << endl;
    }
}