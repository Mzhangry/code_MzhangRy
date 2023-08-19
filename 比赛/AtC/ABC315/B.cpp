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
    int m;
    cin >> m;
    vector<int> d(m);
    for (int i=0;i<m;i++) cin >> d[i];
    int sum = 0;
    for (int i=0;i<m;i++) sum += d[i];
    int ans = (sum + 1) / 2;
    for (int i=0;i<m;i++) {
        if (ans > d[i]) ans -= d[i];
        else {cout << i+1 << ' ' << ans << endl; return 0;}
    }
}