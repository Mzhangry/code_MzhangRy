// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int n, k;
int f[100005];
int main() {
    f[0] = 1;
    cin >> n >> k;
    for (int i=1;i<=k;i++) f[i] = (i+1) % 5000011;
    for (int i=k+1;i<=n;i++) f[i] = (f[i-1] + f[i-k-1]) % 5000011;
    cout << f[n];
}