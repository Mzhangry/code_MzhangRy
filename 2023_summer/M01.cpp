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


vector<int> c, v;

ll solve (int a) {
    
}

int main() {
    int n, l;;
    c.resize(n+1); v.resize(n+1); v[1] = 1;
    for (int i=1;i<=n;i++) cin >> c[i];
    for (int i=2;i<=n;i++) v[i] = v[i-1] * 2;
    cout << solve (l) << endl;
}