// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n, a[1005], max = 0, x = 1;
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=1;i<n;i++) {
        if (a[i] != a[i-1]) x = 1;
        else x ++;
        if (x > max) max = x;
    }
    cout << max;
}