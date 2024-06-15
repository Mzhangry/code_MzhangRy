// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int h, w, k;
const int inf = 1e9;
int main() {
    cin >> h >> w >> k;
    vector< vector<char> > e(h+1, vector<char> (w+1));
    vector< vector<int> > x(h+1, vector<int> (w+1)), o(h+1, vector<int> (w+1)), d(h+1, vector<int> (w+1));
    for (int i=1;i<=h;i++) {
        for (int j=1;j<=w;j++) {
            cin >> e[i][j];
            o[i][j] = o[i][j-1], x[i][j] = x[i][j-1], d[i][j] = d[i][j-1];
            if (e[i][j] == 'o')  o[i][j]++;
            else if (e[i][j] == 'x') x[i][j]++;
            else d[i][j]++;
        }
    }
    int ans = inf;
    for (int i=1;i<=h;i++) {
        for (int j=k;j<=w;j++) {
            if (x[i][j] - x[i][j-k] == 0) ans = min(ans, d[i][j] - d[i][j-k]);
        }
    }

    for (int i=1;i<=h;i++) for (int j=1;j<=w;j++) o[i][j] = x[i][j] = d[i][j] = 0;


    for (int i=1;i<=h;i++) {
        for (int j=1;j<=w;j++) {
            o[i][j] = o[i-1][j], x[i][j] = x[i-1][j], d[i][j] = d[i-1][j];
            if (e[i][j] == 'o')  o[i][j]++;
            else if (e[i][j] == 'x') x[i][j]++;
            else d[i][j]++;
        }
    }

    for (int i=k;i<=h;i++) {
        for (int j=1;j<=w;j++) {
            if (x[i][j] - x[i-k][j] == 0) ans = min(ans, d[i][j] - d[i-k][j]);
        }
    }

    if (ans == inf) cout << -1 << endl;
    else cout << ans << endl;
}