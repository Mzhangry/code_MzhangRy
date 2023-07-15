// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int n;
string s;
int ans = 0;

void dp (int l, int r, char a = 0, char b = 0) {
    if (l == n) return;
    if (r == n) {
        dp(l+1, l+1, s[l+1]);
        return;
    }
    if (s[r] == a || s[r] == b) {
        ans++;
        dp (l, r+1, a, b);
    } else if (b==0) {
        ans++;
        dp (l, r+1, a, s[r]);
    } else {
        dp (l+1, l+1, s[l+1]);
    }
    return;
}
int main() {
    cin >> n;
    cin >> s;
    dp (0, 0, s[0]);
    cout << ans;
}