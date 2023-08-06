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
int cnt[100005];
int main() {
    cin >> n;
    for (int i=0;i<n;i++) {
        int a; cin >> a;
        cnt[a]++;
    }
    int num1 = 0, numex = 0;
    for (int i=1;i<=n;i++) {
        if (cnt[i] == 1) num1++;
        else if (cnt[i] > 2) numex += cnt[i] - 2;
    }
    int ans = 0;
    if (numex >= num1) ans = numex;
    else ans = numex + (num1 - numex) / 2;
    cout << ans << endl;
}