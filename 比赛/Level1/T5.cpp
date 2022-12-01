// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

bool isZhishu (int a) {
    for (int i=2;i<a;i++) {
        if (a%i==0) return false;
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    for (int i=n;i>1;i--) {
        if (n%i == 0 && isZhishu(i)) {
            cout << i;
            return 0;
        }
    }
}