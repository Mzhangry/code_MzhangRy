// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;

string s, s1;
int t;
char l[300];
vector<char> c[300]; // 每个字符都由什么转来
int main() {
    cin >> t;
    while (t--) {
        cin >> s >> s1;
        int len = s.length();
        memset(l, 0, sizeof(l));
        bool noAns = false;
        for (int i=0;i<len;i++) {
            if (l[s[i]] != 0 && l[s[i]] != s1[i]) {
                noAns = true;
                break;
            } else {
                if (l[s[i]] == 0 && s1[i]!=s[i]) c[s1[i]].push_back(s[i]); 
                l[s[i]] = s1[i];
            }
        }
        if (noAns) {
            cout << -1 << endl;
            continue;
        }

        int cnt = 0; // 闲置字符
        for (int i='a';i<='z';i++) if (!l[i]) cnt++;
        for (int i='A';i<='Z';i++) if (!l[i]) cnt++;
        // cout << cnt << ' ';
        int ans = 0;
        for (int i='A';i<='z';i++) {
            if (l[i] != i && l[i] != 0) {
                ans += 1;
                int d = l[i];
                bool circle = false;
                bool morethantwice = false;
                while (1) {
                    if (!l[d] || d == l[d]) break;
                    if (c[d].size() >= 2) morethantwice = true;
                    if (d == i) {
                        circle = true;
                        break;
                    }
                    d = l[d];
                }
                if (circle) {
                    if (!morethantwice) {
                        if (cnt == 0) {
                            noAns = true;
                            break;
                        }
                        ans += 2;
                    }
                    cout << morethantwice << ' ';
                    l[i] = 0;
                }
            }
            if (i == 'Z') i = 'a' - 1;
        }
        if (noAns) {
            cout << -1 << endl;
            continue;
        }

        cout << ans << endl;
    }
}