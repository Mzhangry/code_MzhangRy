// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int cnt[39];
int main() {
    string s;
    cin >> s;
    for (char d : s) {
        cnt[d-'a'] ++;
    }
    int mx = 0;
    for (int i=0;i<26;i++) {
        mx = max(mx, cnt[i]);
    }
    for (int i=0;i<26;i++) {
        if (cnt[i] == mx) {
            cout << char(i + 'a') << endl;
            return 0;
        }
    }
}