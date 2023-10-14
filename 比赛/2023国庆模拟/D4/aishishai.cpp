// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    memset(vis, 0, sizeof(vis));
    for (int i=2;i*i <= n;i++) { // 可改为i <= sqrt(n)，更快
        if (!vis[i]) for (int j=i*i;j<=n;j+=i) vis[j] = true;
    }
    for (int i=2;i<=n;i++) {
        if (!vis[i]) prime.push_back(i);
    }
}