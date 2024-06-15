// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, t;
int r[2005], c[2005];
int x1, x2;
int main() {
    cin >> n >> t;
    for (int i=1;i<=t;i++) {
        int a; cin >> a;
        if (++r[a/n+(a%n!=0)] == n || ++c[((a-1)%n+1)] == n) {
            cout << i << endl;
            return 0;
        }
        x1 += ((a/n+(a%n!=0)) == ((a-1)%n+1));
        x2 += ((a/n+(a%n!=0)) == (n-((a-1)%n+1)+1));
        if (x1 == n || x2 == n) {
            cout << i << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
}