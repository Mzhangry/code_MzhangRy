// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int w[1000005];
long long ans = 0;
int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> w[i];
    for (int i=0; i<n; i++) {
        int id = upper_bound (w, w+n, w[i] + m) - w;
        ans += id - i - 1;
    }
    cout << ans; 
}