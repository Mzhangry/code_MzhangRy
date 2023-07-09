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
string s[25];
int used[25], can[25][25];
int ans = 0;

void dfs(string Dragon, int a) {
    ans = max(ans, int(Dragon.length()));
    used[a]++;

    for (int i=0;i<n;i++) {
        if (can[a][i] && used[i] < 2) dfs(Dragon + s[i].substr(can[a][i]), i);
    }

    used[a]--;
    return;
}

int main() {
    cin >> n;
    for (int i=0;i<n;i++) cin >> s[i];
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            // if (i==j) continue;
            for (int k=1;k<min(s[i].length(), s[j].length());k++) {
                if (s[i].substr(s[i].length() - k, k) == s[j].substr(0, k)) {
                    can[i][j] = k;
                    break;
                }
            }
        }
    }
    char a;
    cin >> a;
    for (int i=0;i<n;i++) {
        if (s[i][0] == a) dfs(s[i], i);
    }
    cout << ans;
}