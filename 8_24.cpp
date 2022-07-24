// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n, cnt = 1, a[15][15];
    cin >> n;
    int j=0, i=0;
    int Li,Lj;
    while (cnt <= n*n) {
        while (j<n) {
            if (cnt > n*n) break;
            if (i>=0) {
                a[i][j] = cnt;
                cnt++;
                Li = i;
                Lj = j;
            }
            i--;
            j++;
        }
        if (Lj < n-1) {
            j = Lj+1;
            i = Li;
        } else {
            j = Lj;
            i = Li+1;
        }
        while (j>=0) {
            if (cnt > n*n) break;
            if (i<n) {
                a[i][j] = cnt;
                cnt++;
                Li = i;
                Lj = j;
            }
            i++;
            j--;
        }
        if (Li == n-1) {
            j = Lj+1;
            i = Li;
        } else {
            j = Lj;
            i = Li+1;
        }
    } 
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}