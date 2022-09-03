// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int m, n;
const int maxwuli = 1e7 + 5;
int cnt[maxwuli];
int sum[maxwuli];
long long ans = 0;
int main() {
    cin >> m >> n;
    int w;
    for (int i=0;i<m;i++) {
        cin >> w;
        cnt[w] ++;
    }
    for (int i=1;i<=10000000;i++) {
        sum[i] = sum[i-1] + cnt[i];
    }
    for (int i=1;i<=10000000;i++) {
        for (int j=cnt[i];j>0;j--) {
            int l = max(1, i-n), r = min(10000000, i+n);
            ans += sum[r] - sum[l-1] - 1;
        }
    }
    cout << ans/2;
}