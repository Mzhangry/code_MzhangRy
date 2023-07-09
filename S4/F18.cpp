// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int a[55];
bool f[1005];
int main() {
    int v, n;
    cin >> n >> v;
    f[0] = 1;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) {
        for (int j=v;j>=1;j--) {
            if (a[i] > j) break;
            f[j] = f[j] | f[j-a[i]];
        }
    }
    int ans = 0;
    for (int i=0;i<=v;i++) ans += f[i];
    cout << ans;
}