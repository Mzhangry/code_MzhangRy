// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int len = s.length();
        int ans = -1;
        for (int i=0;i<=len-3;i++) {
            string s1 = s.substr(i,3);
            if (s1[1] == 'M') continue;
            int opr = 0;
            if (s1[0] == 'O') opr++;
            if (s1[2] == 'M') opr++;
            if (ans == -1 || opr < ans) ans = opr;
        }
        if (ans == -1) cout << -1 << endl;
        else cout << len-3+ans << endl;
    }
}