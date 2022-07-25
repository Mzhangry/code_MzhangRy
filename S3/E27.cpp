// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int a,k = 8, y[100], num = 0;
    cin >> a;
    while (a>0) {
        y[num] = a%k;
        num++;
        a /= k;
    }
    for (int i=num-1;i>=0;i--) {
        cout << y[i];
    }
}