// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int w[105], v[105];
int f[1005];
string s[1005];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> w[i] >> v[i];
    for (int i=1;i<=n;i++) {
        for (int j=m;j>=0;j--) {
            if (w[i] > j) {
                s[j] += '0';
            } else if (f[j] < f[j-w[i]] + v[i]) {
                f[j] = f[j-w[i]] + v[i];
                s[j] = s[j-w[i]] + '1';
            } else if (f[j] > f[j-w[i]] + v[i]) {
                s[j] = s[j] + '0';
            } else {
                if (s[j] > s[j-w[i]]) s[j] = s[j-w[i]] + '1';
                else s[j] = s[j] + '0';
            }
            //cout << s[j] << endl;
        }
    }
    cout << f[m] << endl << s[m];
}