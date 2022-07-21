// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

bool shizhishu (int x) {
    for (int i=2;i*i<=x;i++) if (x % i == 0) return false;
    return true;
}
int main() {
    int n;
    bool flag = false;;
    cin >> n;
    for (int i=3;i<=n-2;i+=2) {
        if (shizhishu(i) && shizhishu(i+2)) {
            cout << i << ' ' << i+2 << endl;
            flag = true;
        }
    }
    if (!flag) cout << "empty" << endl;
}