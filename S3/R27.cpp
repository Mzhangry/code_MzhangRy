// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n, a, fib[1000010] = {0,1,1};
    cin >> n;
    for (int i=3;i<=1000000;i++) fib[i] = (fib[i-1] + fib[i-2]) % 1000;
    for (int i=0;i<n;i++) {
        cin >> a;
        cout << fib[a] << endl;
    }
}