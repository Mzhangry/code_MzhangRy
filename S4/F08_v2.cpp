// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int w[100005], p[100005];
int w1[1005], p1[1005];
int cnt[15][15];
int f[100005];
int main() {
    int m, n;
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> w[i] >> p[i];
    for (int i=1;i<=n;i++) {
        cnt[w[i]][p[i]]++;
    }
    int all = 0;
    for (int i=1;i<=10;i++) {
        for (int j=1;j<=10;j++) {
            int tmp = 1;
            while (cnt[i][j] > 0) {
                if (cnt[i][j] > tmp) {
                    w1[all] = tmp*i;
                    p1[all] = tmp*j;
                    cnt[i][j] -= tmp;
                } else {
                    w1[all] = cnt[i][j] * i;
                    p1[all] = cnt[i][j] * j;
                    cnt[i][j] = 0;
                }
                tmp *= 2;
                all++;
            }
        }
    }
    for (int i=0;i<all;i++) {
        for (int j=m;j>0;j--) {
            if (w1[i] > j) break;
            f[j] = max(f[j], f[j-w1[i]] + p1[i]);
        }
    }
    cout << f[m];
}