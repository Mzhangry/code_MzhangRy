// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int a[55];
int f[2505];
int main() {
    int v, n;
    cin >> n >> v;
    for (int i=1;i<=v;i++) f[i] = -1;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) {
        for (int j=v;j>0;j--) {
            if (a[i] > j) break;
            if (f[j-a[i]] != -1) f[j] = max(f[j], f[j-a[i]]+1);
        }
    }
    cout << f[v];
}