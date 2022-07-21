// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n, m, a[105][105];
    cin >> n >> m;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> a[i][j];
        }
    }
    int tmp;
    tmp = a[0][m-1];
    a[0][m-1] = a[0][0];
    a[0][0] = a[n-1][0];
    a[n-1][0] = a[n-1][m-1];
    a[n-1][m-1] = tmp;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}