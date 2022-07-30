// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int num (int n, int m) {
    if (m == 0) return 0;
    return n / m + num (m, n % m);
}
int main() {
    int n, m;
    cin >> n >> m;
    if (m > n) swap (m, n);
    cout << num(n, m);
}