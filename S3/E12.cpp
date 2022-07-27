// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n;
    double nowmax = 0, minR = 10000000;
    int bx[1005], by[1005];
    cin >> n;
    for (int i=0;i<n;i++) cin >> bx[i] >> by[i];
    for (int i=0;i<n;i++) {
        nowmax = 0;
        for (int j=0;j<n;j++) {
            if (i==j) continue;
            double juli = sqrt ((bx[i]-bx[j])*(bx[i]-bx[j]) + (by[i]-by[j])*(by[i]-by[j]));
            if (juli > nowmax) nowmax = juli;
        }
        if (nowmax < minR) minR = nowmax;
    }
    cout << fixed << setprecision(4) << minR*minR*3.1415926535;
}