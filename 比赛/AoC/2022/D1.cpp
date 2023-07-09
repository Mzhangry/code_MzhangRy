// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int sum[300];
int main() {
    freopen ("d1.out", "r", stdin);
    int a;
    int i=1;
    while (1) {
        cin >> a;
        if (a == -1) {
            i++;
            continue;
        } else if (a == -2) 
            break;
        sum[i] += a;
    }
    int mx = 0;
    for (int i=1;i<=290;i++) {
        mx = max(mx, sum[i]);
    }
    cout << mx;
}