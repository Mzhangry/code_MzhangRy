// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

bool shizhishu(int n) {
    if (n<2) return false;
    for (int i=2;i*i<=n;i++) {
        if (n % i == 0) return false;
    }
    return true;
}
int main() {
    int s, max = 0;
    cin >> s;
    for (int i=2;i<=s/2;i++) {
        int i1 = s - i;
        if (shizhishu(i1) && shizhishu(i) && i * i1 > max) max = i * i1;
    }
    cout << max;
}