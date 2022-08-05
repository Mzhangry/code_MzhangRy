// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int n;
int f (int n) {
    if (n == 0) return 0;
    if (n < 0) return -1;
    int re = -1;
    int a2 = f(n-2);
    int a5 = f(n-5);
    int a7 = f(n-7);
    if (a2 != -1 && (re == -1 || re > a2)) re = a2 + 1;
    if (a5 != -1 && (re == -1 || re > a5)) re = a5 + 1;
    if (a7 != -1 && (re == -1 || re > a7)) re = a7 + 1;
    return re;
}
int main() {
    cin >> n;
    cout << f(n);
}