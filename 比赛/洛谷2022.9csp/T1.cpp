// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    int n, ans = 0;
    scanf("%d\n", &n);
    string s;
    for (int i=0;i<n;i++) {
        getline(cin, s);
        bool isTitle = true;
        int j;
        for (j=0;j<s.length();j++) {
            if (s[j] != ' ' && s[j] != '#') {
                isTitle = false;
                break;
            } else if (s[j] == '#') break;
        }
        if (j == s.length()) isTitle = false;
        if (!(isTitle && j+1 < s.length() && s[j+1] == ' ')) isTitle = false;
        if (isTitle) {
            int k;
            for (k=j+1;k<s.length();k++) {
                if (s[k] != ' ') break;
            }
            if (k != s.length()) ans++;
        }
    }
    cout << ans;
}