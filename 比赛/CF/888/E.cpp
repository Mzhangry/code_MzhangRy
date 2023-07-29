// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int n, k;
bool p[200005];
int c[200005];
vector<int> e[200005];
long long price[200005];
void calculatep (int a) {
    if (p[a]) price[a] = 0;
    else {
        if (!e[a].size()) price[a] = c[a];
        else {
            long long sum = 0;
            for (int j : e[a]) {
                if (price[j] == -1) calculatep(j);
                sum += price[j];
            }
            price[a] = min(sum, 1LL*c[a]);
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        memset (p, 0, sizeof(p));
        cin >> n >> k;
        for (int i=1;i<=n;i++) e[i].clear();
        for (int i=1;i<=n;i++) price[i] = -1;
        for (int i=1;i<=n;i++) cin >> c[i];
        for (int i=0;i<k;i++) {
            int a; cin >> a;
            p[a] = true;
        }
        for (int i=1;i<=n;i++) {
            int m; cin >> m;
            for (int j=0;j<m;j++) {
                int d; cin >> d;
                e[i].push_back(d);
            }
        }
        for (int i=1;i<=n;i++) {
            if (price[i] == -1) calculatep(i);
            //cout << '*';
        }
        for (int i=1;i<=n;i++) cout << price[i] << ' ';
        cout << endl;
    }
}