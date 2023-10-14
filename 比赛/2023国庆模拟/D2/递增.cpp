// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1000000007;
void moplus(int& a, int b) {a = (a+b) % mod;}
int main() {
    int n, m; cin >> n >> m;
    vector< vector<int> > e(n, vector<int> (m));
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> e[i][j];
        }
        sort(e[i].begin(), e[i].end());
    }
    vector< vector<int> > f(n, vector<int> (m)), sum(n, vector<int> (m));
    for (int i=0;i<m;i++) f[0][i] = 1, sum[0][i] = i+1;
    for (int i=1;i<n;i++) {
        int zj = -1;
        for (int j=0;j<m;j++) {
            while (zj < m-1 && e[i][j] > e[i-1][zj+1]) zj++;
            if (zj != -1) moplus(f[i][j], sum[i-1][zj]);
        }
        for (int j=0;j<m;j++) {
            sum[i][j] = f[i][j]; if (j != 0) moplus(sum[i][j], sum[i][j-1]);
        }
    }
    cout << sum.back().back() << endl;
}