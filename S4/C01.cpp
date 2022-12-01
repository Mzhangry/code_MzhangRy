// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int a[1005];
int f[1005];
int n;
int main() {
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) {
        for (int j=i-1;j>=1;j--) {
            if (a[j] < a[i] && f[j] > f[i]) f[i] = f[j];
        }
        f[i]++;
    }
    int ans = 0;
    for (int i=1;i<=n;i++) ans = max(ans, f[i]);
    cout << ans;
}