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
typedef pair<int, char> P;

int n;
int main() {
    cin >> n;
    vector<bool> vis(n+1);
    vector<P> a(n+1);
    ll red_grean = 0, blue_grean = 0;
    for (int i=1;i<=n;i++) cin >> a[i].first >> a[i].second;
    int last_rg, last_bg;
    for (int i=1;i<=n;i++) if (a[i].second == 'G' || a[i].second == 'R') {last_rg = a[i].first; break;}
    for (int i=1;i<=n;i++) if (a[i].second == 'G' || a[i].second == 'B') {last_bg = a[i].first; break;}
    for (int i=1;i<=n;i++) {
        if (a[i].second == 'G') {
            red_grean += a[i].first - last_rg;
            if (last_bg != last_rg) blue_grean += a[i].first - last_bg;
            last_bg = a[i].first; last_rg = a[i].first;
        } else if (a[i].second == 'R') {
            red_grean += a[i].first - last_rg;
            last_rg = a[i].first;
        } else {
            blue_grean += a[i].first - last_bg;
            last_bg = a[i].first;
        }
    }
    cout << red_grean + blue_grean << endl;
}