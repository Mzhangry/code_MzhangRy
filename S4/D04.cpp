// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int a[105][15];
int main() {
    for (int i=1;i<=100;i++) a[i][1] = i;
    for (int i=1;i<=100;i++) {
        for (int j=2;j<=10;j++) {
            a[i][j] = i;
            for (int k=1;k<=i;k++) {
                a[i][j] = min(a[i][j], max(a[k-1][j-1], a[i-k][j]) + 1);
            }
        }
    }
    int n, m;
    while (cin >> n >> m) {
        cout << a[n][m] << endl;
    }
}