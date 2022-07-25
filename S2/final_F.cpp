// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n,m, a[105][105],ans = 0;
    cin >> n >> m;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> a[i][j];
        }
    }
    int i;
    for (int j=0;j<m;j++) {
        for (i=0;i<n;i++) {
            if (a[i][j] == 0) break;
        }
        if (i == n) ans++;
    }
    cout << ans;
}