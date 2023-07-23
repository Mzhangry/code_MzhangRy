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

int n, q;
ll a[100005];
int main() {
    cin >> n >> q;
    for (int i=1;i<=n;i++) cin >> a[i];
    while (q--) {
        ll k; cin >> k;
        int id = 0, las = -1;
        while (1) {
            id = upper_bound (a+1, a+1+n, k+id) - a - 1;
            if (las == id) break;
            las = id;
        }
        cout << k + id << endl;
    }
}