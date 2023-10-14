// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    int n, m, p; cin >> n >> m >> p;
    int ans = 0;
    while (m <= n) {
        m += p; ans++;
    }
    cout << ans << endl;
}