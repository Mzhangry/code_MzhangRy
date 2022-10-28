// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int a[100010], mx[100010];
int main() {
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) {
        mx[i] = max(a[i], mx[i-1]+a[i]);
    }
    int ans = mx[1];
    for (int i=1;i<=n;i++) {
        ans = max(ans, mx[i]);
    }
    cout << ans;
}