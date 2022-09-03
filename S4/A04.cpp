// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int t, m, n;
int a[105][105];
int main() {
    cin >> t;
    while (t--) {
        cin >> m >> n;
        for (int i=1;i<=m;i++) {
            for (int j=1;j<=n;j++) {
                cin >> a[i][j];
            }
        }
        for (int i=2;i<=n;i++) a[1][i] = a[1][i] + a[1][i-1];
        for (int i=2;i<=m;i++) a[i][1] = a[i][1] + a[i-1][1];
        for (int i=2;i<=m;i++) {
            for (int j=2;j<=n;j++) {
                a[i][j] = max(a[i][j-1], a[i-1][j]) + a[i][j];
            }
        }
        cout << a[m][n] << endl; 
    }
}