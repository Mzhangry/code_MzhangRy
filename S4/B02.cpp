// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int a[100010], sum[100010];
int main() {
    sum[0] = 0;
    int n, m;
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) {
        sum[i] = sum[i-1] + a[i];
    }
    for (int i=0;i<m;i++) {
        int x, y;
        cin >> x >> y;
        cout << sum[y] - sum[x-1] << endl;
    }
}