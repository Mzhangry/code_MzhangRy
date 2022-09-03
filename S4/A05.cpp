// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int a[10005];
int n;
int main() {
    cin >> n;
    for (int i=0;i<=n;i++) a[i] = -1;
    a[2] = 1, a[5] = 1, a[7] = 1;
    for (int i=9;i<=n;i++) {
        if (a[i-2] != -1 && ((a[i-2] + 1 < a[i]) || (a[i] == -1))) a[i] = a[i-2] + 1;
        if (a[i-5] != -1 && ((a[i-5] + 1 < a[i]) || (a[i] == -1))) a[i] = a[i-5] + 1;
        if (a[i-7] != -1 && ((a[i-7] + 1 < a[i]) || (a[i] == -1))) a[i] = a[i-7] + 1;
    }
    cout << a[n] << endl;
}