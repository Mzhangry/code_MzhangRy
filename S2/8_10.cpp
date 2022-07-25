// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    int a[105][105];
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) cin >> a[i][j];
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            cout << a[j][i] << ' ';
        }
        cout << endl;
    }
}