// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n;
    cin >> n;
    char a[15][15],a1[15][15];
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin >> a[i][j];
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin >> a1[i][j];
        }
    }

    // 1
    bool flag1 = true, flag2 = true, flag3 = true, flag4 = true;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (a1[i][j] != a[n-1-j][i]) flag1 = false;
            if (a1[i][j] != a[j][n-1-i]) flag2 = false;
            if (a1[i][j] != a[n-1-i][n-j-1]) flag3 = false;
            if (a1[i][j] != a[i][j]) flag4 = false;
        }
    }

    if (flag4) cout << 4;
    else if (flag1) cout << 1;
    else if (flag2) cout << 2;
    else if (flag3) cout << 3;
    else cout << 5;
}