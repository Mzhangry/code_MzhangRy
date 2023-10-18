// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int n, k;
int s[105][105];
const int inf = 1e9;
int mid, num;
int cul (int l, int r, int row) {
    auto sum = [=] (int l, int r) {return (l+r) * (r-l+1) / 2;};
    if (r <= mid) return sum (mid-r, mid-l) + abs(row - mid) * num;
    else if (l >= mid) return sum (l-mid, r-mid) + abs(row - mid) * num;
    else return sum(0, mid-l) + sum(0, r-mid) + abs(row - mid) * num;
}
int main() {
    cin >> n >> k; mid = (k+1) / 2;
    for (int i=1;i<=k;i++) for (int j=1;j<=k;j++) s[i][j] = s[i][j-1] + 1;
    while (n--) {
        int ansv = inf; P ansst;
        cin >> num;
        for (int i=1;i<=k;i++) {
            for (int j=1;j<=k-num+1;j++) {
                int l = j, r = j+num-1;
                if (s[i][r] - s[i][l-1] < num) continue;
                if (cul(l, r, i) < ansv) {
                    ansv = cul(l, r, i), ansst = {i, l};
                }
            }
        }
        if (ansv == inf) {cout << -1 << endl; continue;}
        else {
            cout << ansst.first << ' ' << ansst.second << ' ' << ansst.second + num -1 << endl;
            int cnt = 0;
            for (int i=ansst.second;i<=k;i++) {
                if (cnt < num) cnt++;
                s[ansst.first][i] -= cnt;
            }
        }
    }
}