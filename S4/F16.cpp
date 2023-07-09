// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int a[55];
bool f[2505];
int main() {
    int t;
    cin >> t;
    f[0] = 1;
    while (t--) {
        int n;
        cin >> n;
        for (int i=1;i<=n;i++) cin >> a[i];
        int sum = 0, need;
        for (int i=1;i<=n;i++) sum += a[i];
        if (sum % 3 != 0) {
            cout << "NO";
            return 0;
        } else {
            need = sum/3;
        }
        for (int i=1;i<=need;i++) f[i] = false;
        for (int i=1;i<=n;i++) {
            for (int j=need;j>=0;j--) {
                if (a[i] > j) break;
                f[j] = f[j] | f[j-a[i]];
            }
        }
    }
    
}