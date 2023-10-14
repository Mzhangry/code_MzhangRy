// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    vector<int> ans;
    string t; int n; cin >> n >> t;
    int tlen = t.length();
    for (int _=1;_<=n;_++) {
        string s; cin >> s;
        int slen = s.length();
        if (tlen == slen - 1) {
            int i=0, j=0;
            while (i<slen) {
                if (s[i] == t[j]) j++;
                if (j == tlen) {
                    ans.push_back(_);
                    break;
                }
                i++;
            }
        } else if (tlen == slen + 1) {
            int i=0, j=0;
            while (i<tlen) {
                if (t[i] == s[j]) j++;
                if (j == slen) {
                    ans.push_back(_);
                    break;
                }
                i++;
            }
        } else if (slen == tlen) {
            if (s == t) ans.push_back(_);
            else {
                int cnt = 0;
                for (int j=0;j<slen;j++) {
                    if (s[j] != t[j]) cnt++;
                }
                if (cnt == 1) ans.push_back(_);
            }
        }
    }
    cout << ans.size() << endl;
    for (int d : ans) cout << d << ' ' ;
    cout << endl;
}