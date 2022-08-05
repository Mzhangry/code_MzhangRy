// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int n, ans = 0;
void f(int k, int yu, int last) {
    if (yu == 0) {
        ans ++;
        return;
    }
    for (int i=last;i<=yu;i++) {
        f (k+1, yu-i ,i);
    }
}
int main() {
    while (cin >> n) {
        ans = 0;
        f(1, n, 1);
        cout << ans << endl;
    }
}