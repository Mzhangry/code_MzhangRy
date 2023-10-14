#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int read() {
    int x = 0, w = 1;
    char c = 0;
    while (c < '0' || c > '9') {
        if (c == '-') w = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * w;
}
int main() {
    int n = read();
    vector<int> a(n+1), f(n+1);
    for (int i=1;i<=n;i++) a[i] = read();
    sort(a.begin()+1, a.end());
    for (int i=1;i<=n;i++) {
        f[i] = 1;
        for (int j=1;j<i;j++) {
            if (f[i] % f[j] == 0) f[i] = max(f[i], f[j] + 1);
        }
    }
    int ans = 0;
    for (int i=1;i<=n;i++) ans = max(ans, f[i]);
    cout << n - ans << endl;
}

