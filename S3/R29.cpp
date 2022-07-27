// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int d_sum (int n) {
    if (n == 0) return 0;
    return n%10 + d_sum(n/10);
}
int main() {
    int n;
    cin >> n;
    cout << d_sum(n);
}