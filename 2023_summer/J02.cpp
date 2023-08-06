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
#include<set>
using namespace std;
typedef long long ll;

multiset<int> a;
int main() {
    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
        int d; cin >> d;
        a.insert(d);
    }
    int ans = 0;
    while (!a.empty()) {
        ans++;
        int last = *a.begin();
        a.erase(a.begin());
        while (1) {
            auto it = a.upper_bound(last);
            if (it != a.end()) {
                last = *it;
                a.erase(it);
            } else {
                break;
            }
        }
    }
    cout << ans << endl;
}