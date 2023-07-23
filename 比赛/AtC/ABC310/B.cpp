// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int n, m;
int p[105], c[105];
bool f[105][105];
int main() {
    cin >> n >> m;
    for (int i=1;i<=n;i++) {
        cin >> p[i] >> c[i];
        for (int j=1;j<=c[i];j++) {
            int fd; cin >> fd;
            f[i][fd] = true;
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (p[j] > p[i] || c[j] < c[i]) continue;
            if (p[i] == p[j] && c[i] == c[j]) continue;
            bool flag = true;
            for (int k=1;k<=m;k++) {
                if (f[i][k] && !f[j][k]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}