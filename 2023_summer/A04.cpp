// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int n, k;
int b[1005], bb[1005];
int ans = 0;
int main() {
    cin >> n >> k;
    for (int i=1;i<=n;i++) cin >> b[i];
    for (int i=1;i<=1000;i++) {
        int cnt = 0;
        for (int j=1;j<=n;j++) {
            cnt += b[j]/i;
            bb[j] = b[j] % i;
        }
        if (cnt >= k) ans = max (ans, i*k/2);
        else if (cnt >= k/2) {
            sort (bb+1, bb+1+n, greater<int>());
            int sum = (cnt-k/2) * i;
            for (int j=1;j<=k-cnt;j++) sum += bb[j];
            ans = max (ans, sum);
        }
    }
    cout << ans;
}