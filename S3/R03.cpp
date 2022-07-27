// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int fib (int a) {
    if (a == 1 || a == 2) return 1;
    return fib (a-1) + fib (a-2);
}
int main() {
    int n,a;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> a;
        cout << fib(a) << endl;
    }
}