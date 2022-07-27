// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

bool y[1005];
int main() {
    int a[10], w[10] = {1,2,3,5,10,20};
    for (int i=0;i<6;i++) cin >> a[i];
    y[0] = 1;
    for (int i=0;i<6;i++) {
        for (int j=0;j<a[i];j++) {
            for (int k=1000;k>=0;k--) {
                if (y[k] == true && k+w[i] <= 1000) {
                    y[k+w[i]] = true;
                }
            }
        }
    }
    int ans = 0;
    for (int i=1;i<=1000;i++) {
        if (y[i]) ans++;
    }
    cout << "Total=" << ans;
}