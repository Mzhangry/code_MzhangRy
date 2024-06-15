// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Tri {
    int u, b, c;
};
int n, m;
vector< vector<Tri> > e;
int main() {
    cin >> n >> m;
    e.resize(n+1);
    for (int i=0;i<m;i++) {
        int u, v, b, c; e[v].push_back({u, b, c});
    }
}