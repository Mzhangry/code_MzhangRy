// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int f[105][105];
int main() {
    string s;
    while (cin >> s) {
        if (s == "end") return 0;
        for (int i=0;i<=100;i++) for (int j=0;j<=100;j++) f[i][j] = 0;
        for (int len = 2;len <= s.length();len++) {
            for (int st = 0;st <= s.length() - len;st ++) {
                int ed = st + len - 1;
                if (s[st] == '(' && s[ed] == ')' || s[st] == '[' && s[ed] == ']') f[st][ed] = f[st+1][ed-1] + 2;
                for (int i=st;i<ed;i++) {
                    f[st][ed] = max(f[st][ed], f[st][i] + f[i+1][ed]);
                }
            }
        }
        cout << f[0][s.length()-1] << endl;
    }
}