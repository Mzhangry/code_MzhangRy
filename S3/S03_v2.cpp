// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int a[100010], sum[100010], n;
int main() {
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    sum[0] = 0;
    for (int i=1;i<=n;i++) sum[i] = sum[i-1] + a[i];
    int minsum = 0, ans = -2000000000;
    for (int i=1;i<=n;i++) {
        ans = max(ans, sum[i] - minsum);
        minsum = min(minsum, sum[i]);
    }
    cout << ans;
}