// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n, a, a1[505], m=0, tmp;
    bool flag;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> a;
        if (a % 2 == 1) {
            a1[m] = a;
            m++;
        }
    }
    for (int i=0;i<m-1;i++) {
        flag = true;
        for (int j=0;j<m-1-i;j++) {
            if (a1[j] > a1[j+1]) {
                tmp = a1[j];
                a1[j] = a1[j+1];
                a1[j+1] = tmp;
                flag = false;
            }
        }
        if (flag) break;
    }
    for (int i=0;i<m-1;i++) {
        cout << a1[i] << ',';
    }
    cout << a1[m-1];
}