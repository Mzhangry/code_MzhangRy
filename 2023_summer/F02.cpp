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
int cnt[50];
ll ans = 0;
int main() {
    cin >> n;
    for (int i=1;i<=n;i++) {
        int a; cin >> a;
        int k = 0;
        while (a >> k) k++;
        ans += cnt[k];
        cnt[k]++;
    }
    cout << ans << endl;
}