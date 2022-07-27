// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int a[105];
int sum (int n) {
    if (n-1 == -1) return 0;
    int re = a[n-1] + sum(n-1);
    return re;
}
int main() {
    int n;
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    cout << sum(n);
}