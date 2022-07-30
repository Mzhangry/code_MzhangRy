// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int n, a[15], ans = 0;
void f (int k) {
    if (k == n+1) {
        ans ++;
        return;
    }
    for (int i=1;i<=3;i++) {
        if (i == 2 && a[k-1] == 1) continue;
        a[k] = i;
        f (k+1);
    }
}
int main() {
    cin >> n;
    f(1);
    cout << ans;
    return 0;
}