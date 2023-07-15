// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int mod = 1e9 + 7;
struct CZ
{
    char op;
    int ind, num;
} a[200005];
int n, q;
long long sum[200005];
long long mut = 1;
int main() {
    cin >> n >> q;
    for (int i=0;i<q;i++) {
        cin >> a[i].op;
        if (a[i].op == '+') cin >> a[i].ind >> a[i].num;
        else cin >> a[i].num;
    }
    for (int i=q-1;i>=0;i--) {
        if (a[i].op == '*') mut = mut * a[i].num % mod;
        else sum[a[i].ind] = (sum[a[i].ind] + a[i].num * mut) % mod;
    }
    for (int i=1;i<=n;i++) cout << sum[i] << ' ';
}