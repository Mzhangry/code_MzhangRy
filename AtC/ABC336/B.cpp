// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int ans = 0;
    int x; cin >> x;
    while (x % 2 == 0 && x > 0) x /= 2, ans++;
    cout << ans << endl;
}