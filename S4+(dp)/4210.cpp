// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int n, m;
double d;
const int inf = 1e9;
double a[2005], b[2005];
double f[2005][2005][2];
double gougu (double a, double b) {
    double xlen = abs(b-a);
    return sqrt(d*d + xlen*xlen);
}
int main() {
    cin >> n >> m >> d;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=m;i++) cin >> b[i];
    sort(a+1, a+n+1);
    sort(b+1, b+m+1);

    f[0][0][1] = inf;
    for (int i=1;i<=n;i++) {f[i][0][0] = f[i-1][0][0] + a[i] - a[i-1]; f[i][0][1] = inf;}
    f[0][1][1] = gougu(b[1], 0); f[0][1][0] = inf;
    for (int i=2;i<=m;i++) {f[0][i][1] = f[0][i-1][1] + b[i] - b[i-1]; f[0][i][0] = inf;}
    
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            f[i][j][0] = f[i][j][1] = inf;
            f[i][j][0] = min(f[i-1][j][0] + a[i] - a[i-1], f[i-1][j][1] + gougu(a[i], b[j]));
            f[i][j][1] = min(f[i][j-1][1] + b[j] - b[j-1], f[i][j-1][0] + gougu(a[i], b[j]));
            //f[i][j] = min(f[i-1][j] + a[i] - a[i-1], f[i][j-1] + b[j] - b[j-1]);
            //f[i][j] = min(f[i][j], min(f[i-1][j] + gougu(b[j], a[i]), f[i][j-1] + gougu(a[i], b[j])));
        }
    }
    cout << fixed << setprecision(2) << min(f[n][m][0], f[n][m][1]);
}