// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int a[105][105];
int n;
int main() {
    cin >> n;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin >> a[i][j];
        }
    }
    for (int i=1;i<n;i++) a[0][i] = a[0][i-1] + a[0][i];
    for (int i=1;i<n;i++) a[i][0] = a[i-1][0] + a[i][0];
    for (int i=1;i<n;i++) {
        for (int j=1;j<n;j++) {
            a[i][j] = min (a[i-1][j], a[i][j-1]) + a[i][j];
        }
    }
    cout << a[n-1][n-1];
}