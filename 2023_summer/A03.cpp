// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, long long> P;

const int di = 1e9 + 7;
long long e[200005];
long long mut = 1;
vector<P> a;
int main() {
    int n, q;
    cin >> n >> q;
    while (q--) {
        for (int i=0;i<a.size();i++) a[i].second = a[i].second*mut % di;
        mut = 1;
        char op; cin >> op;
        if (op == '+') {
            int ind, num; cin >> ind >> num;
            a.push_back(make_pair(ind, num));
        } else {
            int num; cin >> num;
            mut = (mut * num) % di;
        }
    }
    for (int i=0;i<a.size();i++) a[i].second = a[i].second*mut % di;
    for (int i=0;i<a.size();i++) e[a[i].first] = (e[a[i].first] + a[i].second) % di;
    for (int i=1;i<=n;i++) cout << e[i] << ' ';
}