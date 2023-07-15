// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int a[100005], mi[100005], sum[100005];
double p[100005], pmx = 0;
vector<int> ans;
int main() {
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    mi[n+1] = 1000000;
    for (int i=n;i>0;i--) {
        sum[i] = sum[i+1] + a[i];
        mi[i] = min(mi[i+1], a[i]);
    }
    for (int i=n-1;i>=2;i--) {
        double pp = (sum[i] - mi[i])*1.0 / (n-i);
        if (pp == pmx) ans.push_back(i-1);
        else if (pp > pmx) {
            ans.clear(); ans.push_back(i-1);
            pmx = pp;
        }
    }
    for (int i=ans.size()-1;i>=0;i--) cout << ans[i] << endl;
}