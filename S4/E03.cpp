// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int t, n;
int a[100005];
int f[100005][2];
int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i=1;i<=n;i++) cin >> a[i];
        for (int i=1;i<=n;i++) {
            f[i][0] = max(f[i-1][0], f[i-1][1]);
            f[i][1] = f[i-1][0] + a[i];
        }
        cout << max(f[n][0], f[n][1]) << endl;
    }
}