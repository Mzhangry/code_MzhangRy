// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int n;
int a[705];
int f[705][3];
int main() {
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) {
        f[i][0] = max(max(f[i-1][0] ,f[i-1][1]) ,f[i-1][2]);
        f[i][1] = f[i-1][0] + a[i];
        f[i][2] = f[i-1][1] + a[i];
    }
    cout << max(f[n][0], max(f[n][1], f[n][2]));
}