// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> task[1005];
int f[1005];
int main() {
    int n, k;
    cin >> n >> k;
    int p, t;
    for (int i=1;i<=k;i++) {
        cin >> p >> t;
        task[p].push_back(t);
    }
    for (int i=n;i>=1;i--) {
        if (task[i].size() == 0) f[i] = f[i+1] + 1;
        else {
            for (int j=0;j<task[i].size();j++) {
                f[i] = max(f[i], f[i+task[i][j]]);
            }
        }
    }
    cout << f[1];
}