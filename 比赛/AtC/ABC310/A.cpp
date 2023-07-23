// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int n, p, q;
int d[105];
int main() {
    cin >> n >> p >> q;
    for (int i=1;i<=n;i++) cin >> d[i];
    int mi = 1e9;
    for (int i=1;i<=n;i++) {
        mi = min (mi, d[i]);
    }
    cout << min (p, q+mi) << endl;
}