// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 3e5 + 10;
int n;
int a[maxn], f[maxn];
int first = -1;
int main() {
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) {
        if (a[i] == -1) {first = i; continue;}
        f[a[i]] = i;
    }
    
    for (int i=first; i != 0; i = f[i]) {
        cout << i << ' ';
    }
    cout << endl;
}