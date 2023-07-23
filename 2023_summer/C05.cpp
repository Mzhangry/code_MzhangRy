// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int n, k;
int a[70000], nxt[70000];
int main() {
    cin >> n >> k; k--;
    for (int i=1;i<=n;i++) cin >> a[i];
    n++;
    sort (a+1, a+1+n, greater<int>());
    for (int i=1;i<n-1;i++) nxt[i] = a[i]/12*12 - (a[i+1]/12+1)*12;
    nxt[n-1] = a[n-1]/12*12;
    int ans = (a[1]/12+1)*12;
    sort (nxt+1, nxt+n, greater<int>());
    for (int i=1;i<=k;i++) {
        if (nxt[i] > 0) ans -= nxt[i];
    }
    cout << ans;
}