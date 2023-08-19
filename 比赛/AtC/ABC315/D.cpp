// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;
typedef long long ll;

int main() {
    int h, w; cin >> h >> w;
    vector< vector<char> > e(h, vector<char> (w)), m(h, vector<char> (w));
    for (int i=0;i<h;i++) for (int j=0;j<w;j++) cin >> e[i][j];
    m = e;
    vector<int> kindh (h), kinds (w);
    vector< vector<int> > cnth (h, vector<int> (26)), cnts (w, vector<int> (26));
    vector< set<int> > existh(h), exists(w);
    for (int i=0;i<h;i++) for (int j=0;j<w;j++) {
        int c = e[i][j] - 'a';
        if (cnth[i][c] == 0) kindh[i]++;
        cnth[i][c]++;

        if (cnts[j][c] == 0) kinds[j]++;
        cnts[j][c]++;

        existh[i].insert(c); exists[j].insert(c);
    }
    ll ans = h*w;
    queue<int> qh, qs;
    for (int i=0;i<h;i++) {
        if (kindh[i] == 1) qh.push(i);
    }
    for (int i=0;i<w;i++) {
        if (kinds[i] == 1) qs.push(i);
    }
    while (1) {
        if (qh.empty() && qs.empty()) break;
        while (!qh.empty()) {
            int i = qh.front(); qh.pop();
            for (int j=0;j<w;j++) {
                if (e[i][j] != '.') e[i][j] = '!';
            }
        }

        while (!qs.empty()) {
            int i = qs.front(); qs.pop();
            for (int j=0;j<h;j++) {
                if (e[j][i] != '.') e[j][i] = '!';
            }
        }

        for (int i=0;i<h;i++) {
            for (int j=0;j<w;j++) {
                if (e[i][j] == '!') {
                    e[i][j] = '.';
                    ans--;
                    int pre = m[i][j] - 'a';
                    if (--cnth[i][pre] == 0) {
                        kindh[i]--;
                        auto it = existh[i].find(pre);
                        existh[i].erase(it);
                        if (kindh[i] == 1 && cnth[i][*existh[i].begin()] >= 2) {
                            qh.push(i);
                        }
                    }

                    if (--cnts[j][pre] == 0) {
                        kinds[j]--;
                        auto it = exists[j].find(pre);
                        exists[j].erase(it);
                        if (kinds[j] == 1 && cnts[j][*exists[j].begin()] >= 2) {
                            qs.push(j);
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}