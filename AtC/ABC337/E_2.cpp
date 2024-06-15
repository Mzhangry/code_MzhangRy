// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<int> e[100];
int main() {
    cin >> n;
    int cnt = 0;
    while ((1 << cnt) < n) cnt++;
    cout << cnt << endl;

    for (int i=0;i<cnt;i++) {
        for (int b=0;b<n;b++) if (b & (1 << i)) {
            e[i].push_back(b+1);
        }
        cout << e[i].size() << ' ';
        for (int d : e[i]) cout << d << ' ';
        cout << endl;
    }

    string s; cin >> s;
    int ans = 0;
    for (int i=0;i<s.size();i++) {
        if (s[i] == '1') ans |= 1 << i;
    }
    cout << ans+1 << endl;
}