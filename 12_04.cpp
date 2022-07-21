// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int x, y, ans;
    char c;
    cin >> x >> c >> y;
    if (c == '+') ans = x + y;
    else if (c == '-') ans = x - y;
    else if (c == '*') ans = x * y;
    else if (c == '/') ans = x / y;
    else ans = x % y;
    cout << ans;
    return 0;
}