// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string t;
vector<int> head, tail;
int tlen = t.length();
void culc (string s) {
    int si = 0, ti = 0;
    while (si < s.length()) {
        if (s[si] == t[ti]) ti++;
        if (ti == tlen) break;
        si++;
    }
    head[ti]++; int he = ti;
    si = s.length()-1, ti = tlen - 1;
    while (si >= 0) {
        if (s[si] == t[ti]) ti--;
        if (ti == -1) break;
        si--;
    }
    int ta = tlen - ti - 1;
    tail[ta]++;
}
int main() {
    int n; cin >> n >> t;
    tlen = t.length();
    head.resize(tlen + 1); tail.resize(tlen + 1);
    for (int _=0;_<n;_++) {
        string s; cin >> s;
        culc (s);
    }
    vector<ll> sum (tlen+2);
    for (int i=tlen;i>=0;i--) sum[i] = sum[i+1] + tail[i];
    ll ans = 0;
    for (int i=0;i<=tlen;i++) {
        ans += head[i] * sum[tlen - i];
    }
    cout << ans << endl;
}