// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n,a0[205],a[205],tmp,j,num=0;
    cin >> n;
    for (int i=0;i<n;i++) cin >> a0[i];
    for (int i=0;i<n;i++) {
        for (j=2;j*j<=a0[i];j++) if (a0[i] % j == 0) break;
        if (j*j>a0[i] && a0[i]!=1) {
            a[num] = a0[i];
            num++;
        }
    }
    cout << num << endl;
    for (int i=0;i<num-1;i++) {
        for (int j=0;j<num-1;j++) {
            if (a[j] < a[j+1]) {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
    for (int i=0;i<num;i++) cout << a[i] << ' ';
}