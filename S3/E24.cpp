// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

bool zhi (int a) {
    if (a < 2) return false;
    for (int i=2;i*i<=a;i++) {
        if (a % i == 0) return false;
    }
    return true;
}
bool hui (int a) {
    int x = 0;
    int s = a;
    while (s>0) {
        x = x * 10 + s % 10;
        s /= 10;
    }
    if (x == a) return true;
    else return false;
}
int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i=11;i<=n;i++) {
        if (zhi(i) && hui(i)) ans++;
    }
    cout << ans;
}