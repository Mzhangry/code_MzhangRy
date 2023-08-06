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
    vector<int> a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    ll sum = 0;
    for (int i=0;i<n;i++) sum += a[i];
    ll need = sum / n, yu = sum % n;
    ll cha = 0;
    for (int i=0;i<n;i++) cha += abs((ll)a[i] - need);
    cha -= yu; //if (yu == 0) cha -= need;
    cout << cha / 2 << endl;
    // ll ans1 = 0, ans2 = 0;
    // for (int i=0;i<n;i++) {
    //     ans1 += min(abs(a[i] - need), abs(a[i] - (need-1)));
    //     ans2 += min(abs(a[i] - need), abs(a[i] - (need+1)));
    // }
    // if (yu == 0) ans2 = min(ans1, ans2);
    // cout << (ans2-1)/2+1 << endl;
}