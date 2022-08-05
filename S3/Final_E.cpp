// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int n;
int f(int n) {
    if (n<0) return 0;
    if (n == 0) return 1;
    return f(n-2) + f(n-3) + f(n-4) + f(n-6);
}
int main() {
    cin >> n;
    cout << f(n);
}