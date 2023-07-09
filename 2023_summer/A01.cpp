// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

long long tim[100005];
long long sum[100005];

int main() {
    int n; cin >> n;
    for (int i=1;i<=n;i++) cin >> tim[i];
    for (int i=1;i<=n;i++) sum[i] = sum[i-1] + tim[i];
    long long t; cin >> t;
    t = t % sum[n];
    int id = lower_bound(sum+1, sum+n+1, t) - (sum+1);
    cout << id+1;
}