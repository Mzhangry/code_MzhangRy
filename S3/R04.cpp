// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int f(int n) {
    if (n == 1 || n == 0) return 1;
    return f(n-1) + f(n-2);
}
int main() {
    int a;
    while (cin >> a) {
        cout << f(a) << endl;
    }
}