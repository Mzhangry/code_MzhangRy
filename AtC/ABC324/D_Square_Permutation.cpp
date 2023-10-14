// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int cnt[15];
int ans = 0;
void init() {
    ll maxd = pow(10, n) + 10;
    for (ll i=0;;i++) {
        ll num = i*i; if (num > maxd) return;
        vector<int> need(10);
        while (num) need[num % 10] ++, num /= 10;
        bool flag = true;
        if (cnt[0] < need[0]) {flag = false; continue;}
        for (int j=1;j<=9;j++) if (cnt[j] != need[j]) {flag = false; break;}
        if (flag) {ans++;}
    }
}
int main() {
    cin >> n;
    char c; c = getchar();
    for (int i=0;i<n;i++) {
        c = getchar();
        cnt[c - '0']++;
    }
    init();
    cout << ans << endl;
}