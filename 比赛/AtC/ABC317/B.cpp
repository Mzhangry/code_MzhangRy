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

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    sort (a.begin(), a.end());
    for (int i=1;i<n;i++) {
        if (a[i] != a[i-1] + 1) {
            cout << a[i-1] + 1 << endl;
            return 0;
        }
    }
}