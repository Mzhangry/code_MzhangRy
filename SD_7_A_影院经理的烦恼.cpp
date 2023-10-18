// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
struct Node
{
    int l, r;
};
struct Tri
{
    int v, x, y;
};

const int inf = 1e9;
int cul (int l, int r) {
    
}
int main() {
    cin >> n >> k;
    vector< vector<Node> > e(k+1, vector<Node> (1, {1, k}));
    int mid = (k+1) / 2;
    while (n--) {
        Tri ans = {inf, 0, 0}; int num; cin >> num;
        for (int i=1;i<=k;i++) {
            for (int d=0;d<e[i].size();d++) {
                int r = e[i][d].r, l = e[i][d].l;
                if (r - l + 1 < num) continue;
                int val = 0;
                if (r <= mid) 
            }
        }
    }
}