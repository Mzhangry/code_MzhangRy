// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool a, b, c;
string s;
char s0[4] = {'A', 'B', 'C'};
int cnt = 0;
int main() {
    cin >> s;
    for (int i=0;i<s.length();i++) {
        while (s[i] != s0[cnt] && cnt < 3) cnt++;
        if (cnt == 3) {
            cout << "No" << endl; return 0;
        }
    }
    cout << "Yes" << endl;
}