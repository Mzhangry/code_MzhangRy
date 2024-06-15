// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int sumx, sumy;

int main() {
    cin >> n;
    for (int i=0;i<n;i++) {
        int x, y; cin >> x >> y;
        sumx += x, sumy += y;
    }
    if (sumx > sumy) cout << "Takahashi" << endl;
    else if (sumx == sumy) cout << "Draw" << endl;
    else cout << "Aoki" << endl;
}