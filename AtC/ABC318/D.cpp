// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() { 
    int N;
    cin >> N;
    
    vector D(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            cin >> D[i][j];
        }
    }
    
    vector<ll> dp(1 << N);
    for (int s = 1; s < (1 << N); s++) {
        int x = __builtin_ctz(s);
        dp[s] = max(dp[s], dp[s ^ (1 << x)]);
        for (int i = x + 1; i < N; i++) {
            if (s >> i & 1) {
                dp[s] = max(dp[s], dp[s ^ (1 << x) ^ (1 << i)] + D[x][i]);
            }
        }
    }
    ll ans = dp.back();
    cout << ans;
}