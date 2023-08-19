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

int gcd (int a, int b) {
    return b ? gcd (b, a%b) : a;
}
int main() {
    int n; cin >> n;
    ll ans = 0;
    for (int i=1;i<=n;i++) {
        int a; cin >> a;
        int g = gcd (a, i);
        ans += n / (a/g);
    }
    cout << ans << endl;
}