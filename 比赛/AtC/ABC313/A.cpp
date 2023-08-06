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

int n;
int main() {
    cin >> n;
    vector<int> p;
    for (int i=0;i<n;i++){
        int a; cin >> a;
        p.push_back(a);
    }
    int mx = 0, mxind;
    for (int i=0;i<n;i++) {
        if (p[i] >= mx) {
            mx = p[i];
            mxind = i;
        }
    }
    if (mxind == 0) cout << 0 << endl;
    else cout << mx - p[0] + 1 << endl;
}