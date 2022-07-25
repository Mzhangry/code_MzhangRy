// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int ans[105];
int main() {
    struct XiangmuF
    {
        int y, s;
    };
    
    int n,m,q;
    XiangmuF a[105][105];
    cin >> n >> m >> q;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> a[i][j].s;
            a[i][j].y = i;
        }
    }
    for (int j=0;j<m;j++) {
        for (int i=0;i<n-1;i++) {
            for (int k=0;k<n-1;k++) {
                if (a[k][j].s < a[k+1][j].s) {
                    swap (a[k][j], a[k+1][j]);
                }
            }
        }
    }

    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            ans[a[i][j].y] += max (q-i,0);
        }
    }
    for (int i=0;i<n;i++) cout << ans[i] << ' ';
}