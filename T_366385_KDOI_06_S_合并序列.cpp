// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, n;
int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a (n);
        for (int i=0;i<n;i++) cin >> a[i];
        if (n == 1) cout << "Huoyu" << endl << 0 << endl;
        else if (n == 2) cout << "Shuiniao" << endl;
        else if (n == 3) {
            if ((a[0] ^ a[1] ^ a[2]) == 0) cout << "Huoyu" << endl << 1 << endl << 1 << ' ' << 2 << ' ' << 3 << ' ' << endl;
            else cout << "Shuiniao" << endl;
        } else if (n == 4) {
            if ((a[0] ^ a[1] ^ a[3]) == 0) cout << "Huoyu" << endl << 1 << endl << 1 << ' ' << 2 << ' ' << 4 << ' ' << endl;
            else if ((a[0] ^ a[2] ^ a[3] )== 0) cout << "Huoyu" << endl << 1 << endl << 1 << ' ' << 3 << ' ' << 4 << ' ' << endl;
            else cout << "Shuiniao" << endl;
        } else if (n == 5) {
            bool flag = false;
            for (int i=1;i<=3;i++) {
                if ((a[0] ^ a[i] ^ a[4]) == 0) {
                    cout << "Huoyu" << endl << 1 << endl << 1 << ' ' << i+1 << ' ' << 5 << ' ' << endl;
                    flag = true;
                    break;
                }
            }
            if (flag) continue;
            for (int i=0;i<=2;i++) {
                if ((a[i] ^ a[i+1] ^ a[i+2])== 0) {
                    int sums = a[i] ^ a[i+1] ^ a[i+2];
                    set<int> J; J.insert(i);
                    for (int j=0;j<=4;j++) if (j != i && j != i+1 && j != i+2) {J.insert(j > i ? j-2 : j); sums ^= a[j];}
                    if (!sums) cout << "Huoyu" << endl << 2 << endl << i+1 << ' ' << i+2 << ' ' << i+3 << ' ' << endl << 
                        *J.begin()+1 << ' ' << *(next(J.begin()))+1  << ' ' << *(next(J.begin(), 2)) + 1 << ' ' << endl;
                    flag = true;
                    break;
                }
            }
            if (!flag) cout << "Shuiniao" << endl;
        } else {
            bool flag = false;
            for (int i=1;i<=n-2;i++) {
                if ((a[0] ^ a[i] ^ a[n-1]) == 0) {
                    cout << "Huoyu" << endl << 1 << endl << 1 << ' ' << i+1 << ' ' << n << ' ' << endl;
                    flag = true;
                    break;
                }
            }
            if (!flag) cout << "Shuiniao" << endl;
        }
    }
}