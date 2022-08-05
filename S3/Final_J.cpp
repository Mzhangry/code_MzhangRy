// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int w[1000010], c[1000010];
    for (int i=0;i<n;i++) cin >> w[i];
    for (int i=0;i<n-1;i++) c[i] = w[i+1] - w[i];
    int ans = 0;
    for (int i=0;i<n-1;i++) {
        int sum = 0;
        for (int j=i;j<n-1;j++) {
            sum += c[j];
            if (sum > m) {
                ans += j-i;
                break;
            }
            if (j == n-2 && sum <= m) ans += j-i+1;
        }
    }
    cout << ans << endl;
}