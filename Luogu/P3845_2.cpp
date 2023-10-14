// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x;
}
int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector< vector<P> > e;
        while (n--) {
            int a = read(), b = read(); if (a > b) swap (a, b);
            bool flag = false;
            for (auto& d : e) {
                bool flag1 = true;
                for (auto u : d) {
                    if (a < u.first && b > u.second || a > u.first && b < u.second) {
                        flag1 = false; break;
                    }
                }
                if (flag1) {
                    d.push_back({a, b});
                    flag = true;
                    break;
                }
            }
            if (!flag) e.push_back(vector<P> (1, {a, b}));
        }
        cout << e.size() << endl;
    }
}