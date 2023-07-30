// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const int mod = 998244353;

ll dp[3005];
string s;
int main() {
    cin >> s;
    int n = s.length();
    dp[0] = 1;
    for (char c: s) {
        ll dpp[3005];
        memset(dpp, 0, sizeof(dpp));
        if (c != ')') for (int i=0;i<n;i++) dpp[i+1] = (dpp[i+1] + dp[i]) % mod;
        if (c != '(') for (int i=0;i<n;i++) dpp[i] = (dpp[i] + dp[i+1]) % mod;
        swap (dp, dpp);
    }
    cout << dp[0] % mod << endl;
}