// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

bool f[200005];
string s;
string ss[205];
int main() {
    int n, m;
    cin >> n >> m >> s;
    for (int i=1;i<=m;i++) cin >> ss[i];
    for (int i=0;i<s.length();i++) {
        for (int j=1;j<=m;j++) {
            int len = ss[j].length();
            if (i < len - 1) continue;
            string ss1 = s.substr(i - len + 1, len);
            if (ss[j] == ss1 && (i+1 == len || f[i-len])) f[i] = true;
        }
    }
    int ans = 0;
    for (int i=s.length()-1;i>=0;i--) {
        if (f[i]) {
            ans = i + 1;
            break;
        }
    }
    cout << ans;
}