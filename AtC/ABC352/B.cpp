// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string s, t;
int main() {
    cin >> s >> t;
    int t1 = 0, t2 = 0;
    while (t1 < s.size()) {
        if (s[t1] == t[t2]) {
            t1++;
            t2++;
            cout << t2 << ' ';
        } else {
            t2++;
        }
    }
}