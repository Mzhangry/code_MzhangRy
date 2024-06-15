// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int cul_sum(int a) {
    int ans = 0;
    while (a>0) {
        ans += a % 10;
        a /= 10;
    }
    return ans;
}
int main() {
    int n; cin >> n;
    int last = -100;
    for (int i=1;i<=n;i++) {
        if (i % cul_sum(i) == 0) {
            if (i / 10 > last / 10) cout << endl;
            cout << i << ' ';
            last = i;
        }
    }
}