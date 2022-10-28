// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    int a,b;
    cin >> a >> b;
    int g = b/a;
    cout << fixed << setprecision(16) << 1.0*g/b;
}