// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int a[105][105];
int main() {
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=i;j++) {
            cin >> a[i][j];
        }
    }
    for (int i=n-1;i>=1;i--) {
        for (int j=1;j<=i;j++) {
            a[i][j] = min (max(a[i+1][j], a[i+1][j+1]), a[i][j]);
        }
    }
    cout << a[1][1];
}