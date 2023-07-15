// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

int a[100005], b[100005];
ll suma[100005], sumb[100005];
int ans = 0;
int n, m;
int main() {
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=m;i++) cin >> b[i];
    for (int i=1;i<=n;i++) suma[i] = suma[i-1] + a[i];
    for (int i=1;i<=m;i++) sumb[i] = sumb[i-1] + b[i];
    int ib = 1;
    for (int ia=1;ia<=n;ia++) {
        while (suma[ia] != sumb[ib]) {
            if (suma[ia] < sumb[ib]) ia++;
            else ib++;
            ans++;
        }
        ib++;
    }
    cout << ans;
}