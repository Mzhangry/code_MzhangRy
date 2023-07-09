// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int lifang (int a) {
    return a*a*a;
}
int main() {
    int k;
    cin >> k;
    int ans = 0;
    for (int i=1;i<=k;i++) {
        ans += lifang(i);
    }
    cout << ans;
}