// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

string s, sp = "bessie";
long long ans[300005], m[300006];
int c[300005][26], u[26];
int main() {
    cin >> s;
    int len = s.length();
    for (int i=len;i>0;i--) s[i] = s[i-1];
    s[0] = 0;
    for (int i=len;i>=0;i--) {
        for (int j=0;j<26;j++) {
            c[i][j] = u[j];
        }
        u[s[i] - 'a'] = i;
    }
    for (int i=len;i>0;i--) {
        bool flag = true;
        int pos = i-1;
        for (int j=0;j<6;j++) {
            pos = c[pos][sp[j] - 'a'];
            if (!pos) {
                flag = false;
            }
        }
        if (!flag) continue;
        int pp = len + 1 - pos;
        long long d = (long long)(1) * (pp);
        ans[i] = ans[i+1] + m[pos+1] + d;
		m[i] = m[pos+1] + pp;
    }
    cout << ans[1];
}