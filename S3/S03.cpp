// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int a[100010], sum[100010];
int main() {
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    sum[0] = 0;
    for (int i=1;i<=n;i++) sum[i] = sum[i-1] + a[i];
    int ans = 0;
    for (int i=1;i<=n;i++) {
        for (int j=i+1;j<=n;j++) {
            if (sum[j] - sum[i] > ans) ans = sum[j] - sum[i];
        }
    }
    cout << ans;
}