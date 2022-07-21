// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

double m(int x) {
    if (x % 70 == 0) return x/70*0.1;
    else return (x/70+1)*0.1;
}
int main() {
    int n,a;
    cin >> n;
    double ans = 0;
    for (int i=0;i<n;i++) {
        cin >> a;
        ans += m(a);
    }
    cout << fixed << setprecision(1) << ans;
}