// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int a[55];
int f[1005];
int main() {
    int v, n;
    cin >> n >> v;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) {
        for (int j=v;j>0;j--) {
            if (a[i] > j) break;
            if (f[j-a[i]] != 0) f[j] = max(f[j], f[j-a[i]] + 1);
            else if (j-a[i] == 0) f[j] = max(f[j], 1);
        }
    }
    int ans = 0;
    for (int i=1;i<=v;i++) ans = max(ans, f[i]);
    cout << ans;
}