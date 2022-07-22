// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n,m, a[105][105];
    cin >> n >> m;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> a[i][j];
        }
    }
    int d,k;
    for (int j=0;j<m;j++) {
        d = j;
        k = 0;
        while (d >= 0 && k<n) {
            cout << a[k][d] << endl;
            k++;
            d--;
        }
    }
    for (int i=1;i<n;i++) {
        k = i;
        d = m-1;
        while (d >=0 && k<n) {
            cout << a[k][d] << endl;
            k++;
            d--;
        }
    }
}