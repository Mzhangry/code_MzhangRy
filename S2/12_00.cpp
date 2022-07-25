// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

bool shizhishu (int x) {
    if (x<2) return false;
    for (int i=2;i*i<=x;i++) if (x % i == 0) return false;
    return true;
}
int main() {
    int m,n;
    cin >> m >> n;
    for (int i=m;i<=n;i++) if (shizhishu(i) && shizhishu(i/100) && shizhishu(i%100)) cout << i << endl;
    return 0;
}