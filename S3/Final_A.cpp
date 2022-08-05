// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int k = 1, n;
    cin >> n;
    while (k*k<=n) {
        k++;
    }
    cout << k-1;
}