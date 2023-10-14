// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;
void moplus(ll& a, ll b) {a = (a+b) % mod;}
int main() {
    int n; cin >> n;
    string s; cin >> s;
    ll mul = 0, cnt = 0;
    for (int i=n-1;i>=1;i--) {
        moplus(mul, 1);
        if (s[i] > '1' && s[i-1] > '1') {cout << -1 << endl; return 0;}
        moplus(mul, (s[i] - '0' - 1)*mul);
    }
    cout << mul << endl;
}