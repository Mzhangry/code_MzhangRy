// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

bool f[2550][2550];
int a[55];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int j=0;j<=2500;j++) {
            for (int k=0;k<=2500;k++) {
                f[j][k] = false;
            }
        }
        f[0][0] = 1;
        for (int i=1;i<=n;i++) cin >> a[i];
        int sum = 0, need;
        for (int i=1;i<=n;i++) sum += a[i];
        if (sum % 3 != 0) {
            cout << "NO" << endl;
            continue;
        } else need = sum/3;
        for (int i=1;i<=n;i++) {
            for (int j=need;j>=0;j--) {
                for (int k=need;k>=0;k--) {
                    if (a[i] > j && a[i] > k) f[j][k] = f[j][k];
                    else if (a[i] > j) f[j][k] = f[j][k] | f[j][k-a[i]];
                    else if (a[i] > k) f[j][k] = f[j][k] | f[j-a[i]][k];
                    else f[j][k] = f[j][k] | f[j-a[i]][k] | f[j][k-a[i]];
                }
            }
        } 
        if (f[need][need]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}