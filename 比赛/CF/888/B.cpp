// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

int n;
pair<int, int> a[200005];
bool eo[200005];
int main() {
    int t; cin >> t;
    while (t--) {    
        cin >> n;
        for (int i=1;i<=n;i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i=1;i<=n;i++) {
            eo[i] = a[i].first % 2 == 0;
        }
        sort (a+1, a+1+n);
        bool flag = true;
        for (int i=1;i<=n;i++) {
            bool b = a[i].first % 2 == 0;
            if (eo[i] != b) {
                cout << "NO" << endl;
                flag = false;
                break;
            }
        }
        if (flag) cout << "YES" << endl;
    }
}