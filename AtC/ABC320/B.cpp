// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s; cin >> s;
    int ans = 0;
    for (int i=0;i<s.length();i++) {
        for (int j=i;j<s.length();j++) {
            string s1 = s.substr(i, j-i+1);
            string s2 = s1; reverse(s1.begin(), s1.end());
            if (s1 == s2) ans = max(ans, (int)s1.length());
        }
    }
    cout << ans << endl;
}