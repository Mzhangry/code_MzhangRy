// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;

int n, m;
vector< vector<int> > store;
int friendmax[200005];
bool ok (int a) {
    for (int i=0;i<m;i++) {
        int cnt = 0;
        for (int j=0;j<n;j++) {
            if (store[i][j] >= a) cnt++;
        }
        if (cnt >= 2) return true;
    }
    return false;
}
int main() {
    cin >> m >> n;
    for (int i=1;i<=m;i++) {
        vector<int> a;
        for (int j=1;j<=n;j++) {
            int d; cin >> d;
            a.push_back (d);
        }
        store.push_back(a);
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            friendmax[i] = max(friendmax[i], store[j][i]);
        }
    }
    int mi = 1e9;
    for (int i=0;i<n;i++) mi = min(friendmax[i], mi);
    int left = 1, right = mi, mid;
    while (left < right) {
        mid = (left + right + 1) / 2;
        if (ok(mid)) left = mid;
        else right = mid - 1;
    }
    cout << right << endl;
}