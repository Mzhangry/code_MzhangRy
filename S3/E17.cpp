// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

bool check (int u, int d) {
    for (int i=2;i<=u;i++) {
        if (u % i == 0 && d % i == 0) return false;
    }
    return true;
}
int main() {
    int n, cnt = 0;
    cin >> n;
    int a[605];
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (i == j) continue;
            if (a[i] < a[j] && check(a[i], a[j])) {
                cnt++;
            }
        }
    }
    cout << cnt;
}