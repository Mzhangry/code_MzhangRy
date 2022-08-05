// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n, a[1010];
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) {
        for (int j=i+1;j<=n;j++) {
            if (a[i] == a[j]) {
                cout << i << ' ' << j << endl;
                return 0;
            }
        }
    }
}