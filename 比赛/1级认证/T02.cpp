// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    double ans = a*1.0/b*c;
    printf("%.6lf", ans);
}