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

int n;
int l[3];
int main() {
    cin >> n;
    vector<int> f(n+1, -1); f[0] = 0;
    for (int i=0;i<3;i++) cin >> l[i];
    for (int i=1;i<=n;i++) {
        for (int d : l) {
            if (i-d >= 0 && f[i-d] != -1) f[i] = max (f[i], f[i-d] + 1);
        }
    }
    cout << f[n] << endl;
}