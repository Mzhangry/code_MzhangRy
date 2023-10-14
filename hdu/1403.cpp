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

const int maxn = 2e5 + 10;
string s1, s2, s;
int sa[maxn], rk[maxn], height[maxn], t1[maxn], t2[maxn], cnt[maxn];
int n;
void cul_sa () {
    int m = 127;
    int *x = t1, *y = t2;
    memset(cnt, 0, sizeof(cnt));
    for (int i=0;i<n;i++) cnt[x[i] = s[i]]++;
    for (int i=1;i<=m;i++) cnt[i] += cnt[i-1];
    for (int i=n-1;i>=0;i--) sa[--cnt[x[i]]] = i;

    for (int k=1;k<=n;k<<=1) {
        int p = 0;
        for (int i=n-k;i<n;i++) y[p++] = i;
        for (int i=0;i<n;i++) if (sa[i] >= k) y[p++] = sa[i] - k;

        for (int i=0;i<=m;i++) cnt[i] = 0;
        for (int i=0;i<n;i++) cnt[x[y[i]]]++;
        for (int i=1;i<=m;i++) cnt[i] += cnt[i-1];
        for (int i=n-1;i>=0;i--) sa[--cnt[x[y[i]]]] = y[i];
        swap (x, y);
        p = 1; x[sa[0]] = 0;
        for (int i=1;i<n;i++) {
            x[sa[i]] = y[sa[i-1]] == y[sa[i]] && y[sa[i-1] + k] == y[sa[i] + k] ? p - 1 : p++;
        }
        if (p >= n) {
            for (int i=0;i<n;i++) rk[i] = x[i];
            break;
        }
        m = p;
    }
}
void cul_height () {
    int k = 0, j;
    for (int i=0;i<n;height[rk[i++]] = k) {
        if (rk[i] == 0) continue;
        for (k ? k-- : 0, j = sa[rk[i] - 1];s[i+k] == s[j+k];k++);
    }
}
int main() {
    while (cin >> s1 >> s2) {
        s = s1 + '$' + s2; n = s.length();
        cul_sa(); cul_height();
        int n1 = s1.length();
        int ans = 0;
        for (int i=0;i<n;i++) {
            if (height[i] > ans && ((sa[i-1] < n1 && sa[i] > n1) || (sa[i-1] > n1 && sa[i] < n1))) ans = height[i];
        }
        cout << ans << endl;
    }
}