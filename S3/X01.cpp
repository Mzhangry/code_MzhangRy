// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int n, t;
int f(int n) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    return ( f(n-1) + f(n-3) ) % 10007;
}
int main() {
    cin >> t;
    for (int i=0;i<t;i++) {
        cin >> n;
        cout << f(n) << endl;
    }
}