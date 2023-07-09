// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int a[105];
bool f[10005];
int main() {
    f[0] = 1;
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    int sum = 0, need;
    for (int i=1;i<=n;i++) sum += a[i];
    if (sum % 2 == 1) {
        cout << "NO" << endl;
        return 0;
    } else {
        need = sum/2;
    }
    for (int i=1;i<=n;i++) {
        for (int j=need;j>=1;j--) {
            if (a[i] > j) break;
            f[j] = f[j-a[i]] | f[j];
        }
    }
    if (f[need]) cout << "YES";
    else cout << "NO";
}