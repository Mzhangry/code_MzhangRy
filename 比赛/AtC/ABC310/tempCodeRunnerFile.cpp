// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int n;
string s[200005];
int main() {
    cin >> n;
    for (int i=0;i<n;i++) cin >> s[i];
    for (int i=0;i<n;i++) {
        if (s[i][0] > s[i][s[i].length()-1]) {
            reverse(s[i].begin(), s[i].end());
        }
    }
    sort (s, s+n);
    int cnt = 1;
    for (int i=1;i<n;i++) {
        if (s[i][0] == s[i][s[i].length()-1]) {
            if (s[i] == s[i-1]) continue;
            else {
                reverse(s[i].begin(), s[i].end());
            }
        }
        if (s[i] != s[i-1]) cnt++;
    }
    cout << cnt << endl;
    return 0;
}