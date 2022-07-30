// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

long long mi (int a, int b, int c) {
    if (b == 1) return a;
    long long t = mi (a, b/2, c);
    t = t*t % c;
    if (b % 2 == 1) t = t*a % c;
    return t % c;
}
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << mi(a, b, c) << endl;
}