// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int a[205][8];
int main() {
    a[1][1] = 1;
    int n, k;
    cin >> n >> k;
    for (int i=2;i<=n;i++) {
        for (int j=1;j<=k;j++) {
            a[i][j] = a[i-1][j-1];
            if (i>j) a[i][j] += a[i-j][j];
        }
    }
    cout << a[n][k];
}