// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n,m, a[105][105], ans = 0;
    int d1[10] = {-1,-1,0,1,1,1,0,-1,0},
        d2[10] = {0,1,1,1,0,-1,-1,-1,0};
    cin >> n >> m;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> a[i][j];
        }
    }
    for (int i=1;i<n-1;i++) {
        for (int j=1;j<m-1;j++) {
            bool flag = true;
            for (int k=0;k<9;k++) {
                if (a[i - d1[k]][j - d2[k]] != 0) flag = false;
            }
            if (flag) ans ++;
        }
    }
    cout << ans;
}