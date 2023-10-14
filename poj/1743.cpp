// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e4 + 10;
int n;
int s[maxn];
int height[maxn], t1[maxn], t2[maxn], sa[maxn], cnt[maxn], rk[maxn];
int read(){
    int f=1,k=0;//f是正负号,k用来将字符转换成数字
    char c=getchar();//读入一个字符 //非数字 
    while(c<'0'||c>'9'){//读到空格后
    c=getchar();//读入空格等。 
    }//数字 
    while(c>='0'&&c<='9'){
        k=k*10+c-'0';
        c=getchar();
    }
    return f*k;
}
void cul_sa () {
    int p = 0, *x = t1, *y = t2, m = 200;
    memset(cnt, 0, sizeof(cnt));
    for (int i=0;i<n;i++) cnt[x[i] = s[i]]++;
    for (int i=1;i<=m;i++) cnt[i] = cnt[i] + cnt[i-1];
    for (int i=n-1;i>=0;i--) sa[--cnt[x[i]]] = i;

    for (int k=1;k<=n;k<<=1) {
        p = 0;
        for (int i=n-k;i<n;i++) y[p++] = i;
        for (int i=0;i<n;i++) if (sa[i] >= k) y[p++] = sa[i] - k;

        for (int i=0;i<=m;i++) cnt[i] = 0;
        for (int i=0;i<n;i++) cnt[x[y[i]]]++;
        for (int i=1;i<=m;i++) cnt[i] += cnt[i-1];
        for (int i=n-1;i>=0;i--) sa[--cnt[x[y[i]]]] = y[i];

        swap(x, y); x[sa[0]] = 0; p = 1;
        for (int i=1;i<n;i++) {
            x[sa[i]] = y[sa[i]] == y[sa[i-1]] && y[sa[i] + k] == y[sa[i-1] + k] ? p-1 : p++;
        }
        if (p >= n) {
            for (int i=0;i<n;i++) rk[i] = x[i];
            break;
        }
        m = p;
    }
}

void cul_height() {
    int p = 0, j;
    for (int i=0;i<n;height[rk[i++]] = p) {
        if (rk[i] == 0) continue;
        for (p?p--:0, j=sa[rk[i]-1];s[i+p] == s[j+p];p++);
    }
}

bool check (int mid) {
    int mx = s[0], mi = sa[0]; int i;
    for (i=1;i<=n;i++) {
        if (height[i] >= mid) {
            mi = min(mi, sa[i]); mx = max(mx, sa[i]);
            if (mx - mi + 1 >= mid) return true;
        } else {
            mi = mx = sa[i];
        }
    }
    return false;
}

int main() {
    // ios::sync_with_stdio(false);
    while (cin >> n) {
        if (n == 0) return 0;
        // int cf[maxn];
        // for (int i=0;i<n;i++) cin >> s[i]; cf[0] = s[0] + 100;
        // for (int i=1;i<n;i++) cf[i] = (s[i] - s[i-1]) + 100;
        for(int i=0;i<n;i++){
			s[i] = read();
			if(i)
			s[i-1]=s[i]-s[i-1]+88;
		}
		n--; s[n] = 0;
        //memcpy(s, cf, sizeof(s));
        cul_sa(); cul_height();
        int l = 0, r = maxn; int ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(mid)) {l = mid+1; ans = max(ans, mid);}
            else r = mid-1;
        }
        if (ans >= 4) printf("%d\n", ans+1);
        else printf("0\n");
    }
}