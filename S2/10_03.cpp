// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n,k,tmp;
    double c[105], tmp1;
    int    a[105];
    bool flag;
    cin >> n >> k;
    for (int i=0;i<n;i++) cin >> a[i] >> c[i];
    for (int i=0;i<n-1;i++) {
        flag = true;
        for (int j=0;j<n-1-i;j++) {
            if (c[j] < c[j+1]) {
                tmp1 = c[j];
                c[j] = c[j+1];
                c[j+1] = tmp1;
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                flag = false;
            }
        }
        if (flag) break;
    }
    cout << a[k-1] << ' ' << c[k-1];
}