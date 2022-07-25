// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n, ans = 10000000;
    cin >> n;
    for (int a=1;a<=n;a++) {
        for (int b=1;b<=n;b++) {
            if (n % (a*b) == 0) {
                if (2 * (a*b + b*(n/(a*b)) + a*(n/(a*b))) < ans) {
                    ans = 2 * (a*b + b*(n/(a*b)) + a*(n/(a*b)));
                }
            }
        }
    }
    cout << ans;
}