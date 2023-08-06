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

int n, k;
int ans[1005];
bool ask(int st) {
    cout << '?' << ' ';
    for (int i=st;i<st+k;i++) {
        cout << i << ' ';
    }
    cout << endl;
    int a; cin >> a;
    return a;
}
bool headask(int num) {
    cout << '?' << ' ';
    for (int i=1;i<=k;i++) if (i!=num) cout << i << ' ';
    cout << n << endl;
    int a; cin >> a;
    return a;
}
int main() {
    cin >> n >> k;
    bool last = ask(1);
    bool qianwu = last;
    for (int i=2;i<=n-k+1;i++) {
        int now = ask(i);
        if (now != last) ans[i+k-1] = ans[i-1];
        last = now;
    }

    for (int i=1;i<=k;i++) {
        if (headask(i) == qianwu) ans[i] = ans[n];
        else ans[i] = !ans[n];
    }
    cout << '!' << ' ';
    for (int i=1;i<=n;i++) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}