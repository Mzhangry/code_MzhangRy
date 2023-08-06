// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;

int main() {
    int t; cin >> t;
    while (t--) {
        int m; cin >> m;
        for (ll S = 1;;S++) {
            ll a = 0, mul = 1;
            for (int i=0;i<=60;i++) {
                if ((S >> i) & 1) a += mul;
                mul *= 10;
            }
            if (a % m == 0) {
                cout << a << endl;
                break;
            }
        }
    }
}