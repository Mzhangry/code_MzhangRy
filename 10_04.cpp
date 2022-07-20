// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n, a[505], tmp;
    bool flag;
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n-1;i++) {
        flag = true;
        for (int j=0;j<n-1-i;j++) {
            if (a[j] > a[j+1]) {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                flag = false;
            }
        }
        if (flag) break;
    }
    flag = false;
    for (int i=0;i<n;i++) {
        if (a[i] % 2 == 1) {
            if (flag) cout << ',' << a[i];
            else {
                cout << a[i];
                flag = true;
            }
        }
    }
    return 0;
}