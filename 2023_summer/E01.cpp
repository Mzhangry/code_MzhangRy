// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;

string a, b;
bool ans[105];
int main() {
    cin >> a >> b;
    reverse (a.begin(), a.end());
    reverse (b.begin(), b.end());
    for (int i=0;i<min(a.length(), b.length());i++) {
        if (a[i] != b[i]) ans[i] = true;
        else ans[i] = false;
    }
    string c;
    if (a.length() > b.length()) c = a;
    else c = b;
    for (int i=min(a.length(), b.length()); i<c.length(); i++) {
        if (c[i] == '1') ans[i] = true;
    }
    for (int i=100;i>=0;i--) {
        if (ans[i]) {
            for (int j=i;i>=0;i--) {
                cout << (int)ans[i];
            }
            cout << endl;
            return 0;
        }
    }
    cout << 0 << endl;
}
