// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int a[1005][1005];
    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin >> a[i][j];
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (a[i][j] == 0) {
                int d = i,k = j;
                while (a[d][j] == 0 && d<n) d++;
                while (a[i][k] == 0 && k<n) k++;
                cout << (d-i-2)*(k-j-2) << endl;
                return 0;
            }
        }
    }
}