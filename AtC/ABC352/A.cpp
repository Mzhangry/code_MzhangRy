// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
int main() {
    cin >> n;
    int x, y, z;
    cin >> x >> y >> z; if (x > y) swap(x, y);
    if (z >= x && z <= y) cout << "Yes" << endl;
    else cout << "No" << endl;
}