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
#include <atcoder/all>
using namespace std;
using mint = atcoder::modint998244353;
mint dp[2][2][2][10][10][10];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  long long n;
  cin >> n;
  n ++;
  
  int x1, x2, x3;
  cin >> x1 >> x2 >> x3;
  
  mint ans = 0;
  dp[0][0][0][0][0][0] = 1;
  for (int bit = 60; bit >= 0; -- bit) {
    int n = n >> bit & 1;
    mint g[2][2][2][10][10][10];
    for (int f_1 = 0; f_1 <  2; i ++)
    for (int f_2 = 0; f_2 <  2; i ++)
    for (int f_3 = 0; f_3 <  2; i ++)
    for (int g_1 = 0; g_1 < x1; g_1 ++)
    for (int g_2 = 0; g_2 < x2; g_2 ++)
    for (int g_3 = 0; g_3 < x3; g_3 ++)
    for (int x1 = 0; x1 <= (f_1 ? 1 : n); x1 ++) 
    for (int x2 = 0; x2 <= (f_2 ? 1 : n); x2 ++) 
    for (int x3 = 0; x3 <= (f_3 ? 1 : n); x3 ++) 
      if ((x1 ^ x2 ^ x3) == 0) {
       g[f_1 || x1 < n]
        [f_2 || x2 < n]
        [f_3 || x3 < n]
        [(g_1 * 2 + x1) % x1]
        [(g_2 * 2 + x2) % x2]
        [(g_3 * 2 + x3) % x3]
          += dp[f_1][f_2][f_3][g_1][g_2][g_3];
      }
      swap(dp, g);
  }
  
  ans = dp[1][1][1][0][0][0];
  n --; 
  ans -= n / lcm(x1, x2);
  ans -= n / lcm(x1, x3);
  ans -= n / lcm(x2, x3);
  cout << ans - 1 << '\n';
  
  return 0;
}