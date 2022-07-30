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
    int x, y;
    cin >> x >> y;
    if (y < x) swap (x, y);
    int ans = 0;
    for (int i=x;i<=y;i++) {
        if (shizhishu(i)) ans++;
    }
    cout << ans << endl;
}