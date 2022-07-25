// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[1005];
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (i == j) continue;
            if (a[i] + a[j] == k) {
                cout << "yes";
                return 0;
            }
        }
    }
    cout << "no";
}