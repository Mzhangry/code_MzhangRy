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
    int n, h, x; cin >> n >> h >> x;
    for (int i=1;i<=n;i++) {
        int a; cin >> a;
        if (a + h >= x) {
            cout << i << endl;
            return 0;
        }
    }
}