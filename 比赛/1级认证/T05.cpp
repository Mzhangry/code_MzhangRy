// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

bool zizheng(int a) {
    int d = a;
    int sum = 0;
    while (d>0) {
        sum += d%10;
        d/=10;
    }
    if (a % sum == 0) return true;
    else return false;
}
int main() {
    int n;
    cin >> n;
    for (int i=10;i<=n;i++) {
        if (zizheng(i)) cout << i << endl;
    }
}