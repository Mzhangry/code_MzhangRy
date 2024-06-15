// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int x[105], y[105];
const int inf = 1e9+10;
int main() {
    int n;
    cin >> n;
    for (int i=0;i<n;i++) cin >> x[i] >> y[i];
    for (int i=0;i<n;i++) {
        int mx = 0; double dis = -inf;
        for (int j=0;j<n;j++) if (i != j) {
            double d = sqrt((x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]));
            if (d > dis) mx = j, dis = d;
        }
        cout << mx + 1 << endl;
    }
}