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
int num[100005];
int main() {
    cin >> n;
    for (int i=1;i<=n;i++) {
        int a; cin >> a;
        num[a] = i; 
    }
    int mx = -1, ans = 0;
    for (int i=1;i<=n;i++) {
        int c = abs (i - num[i]);
        if (c > mx || c == mx && num[i] + 1 != num[i-1]) {
            ans = i; mx = c;
        } 
    }
    cout << ans << endl;
}