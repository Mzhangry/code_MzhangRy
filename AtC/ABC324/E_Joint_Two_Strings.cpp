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
        si++;
    }
    head[ti]++;
    si = s.length()-1, ti = tlen - 1;
    while (si >= 0) {
        if (s[si] == t[ti]) ti--;
        si--;
    }
    tail[]
}
int main() {
    int n; cin >> n >> t;
    head.resize(tlen + 1); tail.resize(tlen + 1);
    for (int _=0;_<n;_++) {
        string s; cin >> s;
        culc (s);
    }
}