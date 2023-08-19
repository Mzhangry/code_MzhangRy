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
const int inf = 1e9;
int N, K;
int X[10005], Y[10005];
double dp[10005][10005];
int main() {
    cin >> N;
    double ans = inf;
    for (int i=0;i<n;i++) cin >> X[i] >> Y[i];
    dp[0][0] = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < K; j++) {
            for (int x = i + 1; x < N && j + x - i - 1 < K; x++) {
                int nj = j + x - i - 1;
                dp[x][nj] = std::min(dp[x][nj], dp[i][j] + std::sqrt((X[i] - X[x]) * (X[i] - X[x]) + (Y[i] - Y[x]) * (Y[i] - Y[x])));
            }
        }
    }
    for (int i = 0; i < K; i++) {
        ans = min(ans, dp[N - 1][i] + (i == 0 ? 0 : 1 << (i - 1)));
    }
    cout << std::fixed << std::setprecision(10) << ans << endl;
}