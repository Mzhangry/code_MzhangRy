// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int a[1005];
int n;
int f[1005];
int main() {
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) {
        for (int j=0;j<i;j++) {
            if (a[j] < a[i] && f[j] > f[i]) f[i] = f[j];
        }
        f[i] += a[i];
    }
    int ans = 0;
    for (int i=0;i<n;i++) ans = max(ans, f[i]);
    cout << ans;
}