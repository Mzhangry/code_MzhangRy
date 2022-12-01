// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    int s, ans = 0;
    while (n--) {
        cin >> s;
        if (s>=l && s<=r) ans++;
    }
    cout << ans;
}