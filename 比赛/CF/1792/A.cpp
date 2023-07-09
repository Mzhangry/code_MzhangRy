// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int t;
int main() {
    cin >> t;
    while (t--) {
        int n, h[105];
        cin >> n;
        for (int i=1;i<=n;i++) cin >> h[i];
        int cnt = 0, ans = 0;
        for (int i=1;i<=n;i++) {
            if (h[i] == 1) cnt ++;
            else ans ++;
        }
        ans += (cnt%2 == 0? cnt/2 : cnt/2+1);
        cout << ans << endl;
    }
}