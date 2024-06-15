// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    bool flag = true;
    if (s[0] < 'A' || s[0] > 'Z') flag = false;
    for (int i=1;i<s.length();i++) if (s[i] < 'a' || s[i] > 'z') flag = false;
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}