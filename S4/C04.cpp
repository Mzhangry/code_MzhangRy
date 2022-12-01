// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int k, n;
int a[105], up[105], down[105];
int main() {
    cin >> k;
    while (k--) {
        cin >> n;
        for (int i=0;i<n;i++) {
            up[i] = 0;
            down[i] = 0;
        }
        for (int i=0;i<n;i++) {
            cin >> a[i];
        }
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (a[i] > a[j] && up[j] > up[i]) up[i] = up[j];
                if (a[i] < a[j] && down[j] > down[i]) down[i] = down[j];
            }
            up[i]++;
            down[i]++;
        }
        int ans = 0;
        for (int i=0;i<n;i++) {
            ans = max(ans, max(up[i], down[i]));
        }
        cout << ans << endl;
    }
}