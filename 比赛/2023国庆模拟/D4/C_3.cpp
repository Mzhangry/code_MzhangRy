// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxa = 2e5 + 10;
vector<int> yz[maxa + 5];
void cul_yz() {
    for (int i=1;i<=maxa;i++) {
        for (int j=2*i;j<=maxa;j += i) {
            yz[j].push_back(i);
        }
    }
}
int cnt[maxa], f[maxa];
int main() {
    cul_yz();
    int n; cin >> n;
    for (int i=0;i<n;i++) {int a; cin >> a; cnt[a]++;}
    int ans = 0;
    for (int i=1;i<maxa;i++) {
        if (cnt[i]) {
            f[i] = cnt[i];
            int mx = 0;
            for (int d : yz[i]) {
                mx = max(mx, f[d]);
            }
            f[i] += mx;
            ans = max(ans, f[i]);
        }
    }
    cout << n - ans << endl;
}