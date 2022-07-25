// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n = 10,a[10],tmp;
    bool flag;
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
    for (int i=0;i<n;i++) cout << a[i] << ' ';
}