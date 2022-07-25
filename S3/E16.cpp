// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int a[105], ans = 0;
    int n;
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) {
        bool flag = false;
        for (int j=0;j<n;j++) {
            if (j == i) continue;
            for (int k=j+1;k<n;k++) {
                if (k == i) continue;
                if (a[j] + a[k] == a[i]) {
                    ans ++;
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
    }
    cout << ans;
}