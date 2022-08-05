// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int a[100010], sum[100010];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i];
    int k;
    sum[0] = 0;
    for (int i=1;i<=n;i++) sum[i] = sum[i-1] + a[i];
    for (int i=0;i<m;i++) {
        cin >> k;
        cout << sum[k] << endl;
    }
}