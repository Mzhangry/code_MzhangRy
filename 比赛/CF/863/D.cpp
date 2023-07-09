// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int t;
int fib[50];
bool f(int n, int x, int y) {
    if (n==0) return true;
    if (y <= fib[n] && y > fib[n+1] - fib[n]) return false;
    if (y > fib[n]) return f(n-1, y-fib[n], x);
    else return f(n-1, y, x);
}
int main() {
    fib[0] = fib[1] = 1;
    for (int i=2;i<=48;i++) fib[i] = fib[i-1] + fib[i-2];
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        if (f(n, x, y)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}