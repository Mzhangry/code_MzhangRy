// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int f1[55][2505], f2[50][2505];
int a[55];
int main() {
    int t;
    cin >> t;
    f1[0][0] = f2[0][0] = 1;
    while (t--) {
        int n;
        cin >> n;
        for (int i=1;i<=n;i++) cin >> a[i];
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=2500;j++) {
                f1[i][j] = f2[i][j] = 0;
            }
        }
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=2500;j++) {
                f1[i][j]
            }
        }
    }
}