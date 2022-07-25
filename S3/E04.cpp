// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    for (int i=2;i<=1000000;i++) {
        if (a%i == b%i && b%i == c%i) {
            cout << i;
            return 0;
        }
    }
}