// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int a[10],tmp;
    for (int i=0;i<10;i++) cin >> a[i];
    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            if (a[j] > a[j+1]) {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
    for (int i=0;i<10;i++) {
        cout << a[i] << ' ';
    }
}