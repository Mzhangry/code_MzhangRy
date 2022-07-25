// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n, sum = 0;
    cin >> n;
    for (int i=1;i<100000;i++) {
        sum = 0;
        for (int j=1;j<=i;j++) {
            sum += j;
        }
        for (int j=1;j<=i;j++) {
            if (sum - 2*j == n) {
                cout << j << ' ' << i;
                return 0;
            }
        }
    }
}