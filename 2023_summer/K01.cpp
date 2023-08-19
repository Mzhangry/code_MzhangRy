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

int f[500005];
int main() {
    int k;
    string s; char c1, c2;
    cin >> k >> s >> c1 >> c2;
    for (int i=s.length()-1;i>=0;i--) {
        f[i] = f[i+1];
        if (s[i] == c2) f[i]++;
    }
    ll ans = 0;
    for (int i=0;i<s.length();i++) {
        if (s[i] == c1) {
            ans += f[i+k-1];
        }
    }
    cout << ans << endl;
}