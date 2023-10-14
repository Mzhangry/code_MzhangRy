// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int m; string s1, s2, s3; cin >> m >> s1 >> s2 >> s3; s1 += s1 + s1, s2 += s2 + s2, s3 += s3 + s3;
    for (int i=0;i<=9;i++) {
        vector<int> a[3];
        for (int j=0;j<3*m;j++) {
            if (s1[j] == '0' + i) a[0].push_back(j);
            if (s2[j] == '0' + i) a[1].push_back(j);
            if (s3[j] == '0' + i) a[2].push_back(j);
        }
        int ans = 0;
        if (a[0].size() == 0 || a[1].size() == 0 || a[2].size() == 0) continue;
        ans = a[0][0] + a[1][0] + a[2][0];
        if (a[0][0] == a[1][0] )
        if (a[0][0] == a[1][0]) {
            if (a[0].size() > 1) ans = max(ans, a[0][1] - a[0][0]);
            if (a[1].size() > 1) ans = max(ans, a[1][1] - a[1][0]);
        }
        if (a[0][0] == a[2][0]) {
            if (a[0].size() > 1) ans = max(ans, a[0][1] - a[0][0]);
            if (a[2].size() > 1) ans = max(ans, a[2][1] - a[2][0]);
        }
    }
}