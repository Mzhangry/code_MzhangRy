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
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        bool flag = false;
        for (int i=0;i<s.length();i++) if (s[i] == '.') flag = true;
        if (!flag) s += '.';
        int st=0, ed=s.length()-1;
        for (st=0;st<s.length() && s[st] == '0';st++) ;
        for (;ed>=0 && s[ed] == '0'; ed--) ;
        int firn0=st, pnt=st;
        for (;firn0 <= ed && (s[firn0] == '.' || s[firn0] == '0');firn0++);
        for (;pnt <= ed && s[pnt] != '.';pnt++);
        if (firn0 == ed+1) {
            cout << 0 << endl;
            continue;
        }
        int b;
        if (firn0 < pnt) b = pnt - firn0 - 1;
        else if (firn0 > pnt) b = pnt - firn0;
        for (;ed>=0 && (s[ed] == '0' || s[ed] == '.'); ed--) ;
        for (;st<s.length() && (s[st] == '0' || s[st] == '.');st++) ;
        cout << s[st];
        if (st != ed) cout << '.';
        for (int i=st+1;i<=ed;i++) if (s[i] != '.') cout << s[i];
        if (b != 0) cout << 'E' << b;
        cout << endl;
    }
}