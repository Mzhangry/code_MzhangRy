// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool e[105][105];
int n;
int main() {
    cin >> n;
    while (n--) {
        int x1, x2, y1, y2; cin >> x1 >> x2 >> y1 >> y2;
        for (int i=x1;i<=x2-1;i++) {
            for (int j=y1;j<=y2-1;j++) {
                e[i][j] = true;
            }
        }
    }
    int cnt = 0;
    for (int i=0;i<=100;i++) for (int j=0;j<=100;j++) if (e[i][j]) cnt++;
    cout << cnt << endl;
}