// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n,m,k;
    int a[105][105], b[105][105], c[105][105];
    for (int i=0;i<102;i++) for (int j=0;j<102;j++) c[i][j] = 0;
    cin >> n >> m >> k;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> a[i][j];
        }
    }
    for (int i=0;i<m;i++) {
        for (int j=0;j<k;j++) {
            cin >> b[i][j];
        }
    }

    for (int i=0;i<n;i++) {
        for (int j=0;j<k;j++) {
            for (int d=0;d<m;d++) {
                c[i][j] += a[i][d] * b[d][j];
            }
            cout << c[i][j] << ' ';
        }
        cout << endl;
    }
}