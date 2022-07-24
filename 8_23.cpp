// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

bool pan[105][105];
int main() {
    int n,m;
    int a[105][105];
    cin >> n >> m;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> a[i][j];
        }
    }
    int cnt = 0, i=0, j=0;
    while (cnt < n*m) {
        while (j<m && pan[i][j] == false && cnt <= n*m) {
            cout << a[i][j] << endl;
            pan[i][j] = true;
            cnt ++;
            j++;
        }
        j--;
        i++;
        while (i<n && pan[i][j] == false && cnt <= n*m) {
            cout << a[i][j] << endl;
            pan[i][j] = true;
            cnt ++;
            i++;
        }
        i--;
        j--;
        while (j>=0 && pan[i][j] == false && cnt <= n*m) {
            cout << a[i][j] << endl;
            pan[i][j] = true;
            cnt ++;
            j--;
        }
        j++;
        i--;
        while (i>=0 && pan[i][j] == false && cnt <= n*m) {
            cout << a[i][j] << endl;
            pan[i][j] = true;
            cnt ++;
            i--;
        }
        i++;
        j++;
    }
}