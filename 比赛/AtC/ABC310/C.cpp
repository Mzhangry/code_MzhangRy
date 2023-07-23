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
        string ss = s[i];
        reverse(ss.begin(), ss.end());
        if (ss < s[i]) s[i] = ss;
    }
    sort (s, s+n);
    int cnt = 1;
    for (int i=1;i<n;i++) {
        if (s[i] != s[i-1]) cnt++;
    }
    cout << cnt << endl;
    return 0;
}