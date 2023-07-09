// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int f[5005][5005];
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int len = 2;len <= n;len++) {
        for (int st = 1;st <= n+1-len;st++) {
            int ed = st + len - 1;
            f[st][ed] = min(f[st+1][ed] + 1, f[st][ed-1] + 1);
            if (s[st-1] == s[ed-1]) f[st][ed] = min(f[st][ed], f[st+1][ed-1]);
        }
    }   
    cout << f[1][n];
}