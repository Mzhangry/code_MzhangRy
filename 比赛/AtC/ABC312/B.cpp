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

int n, m;
char a[105][105];
char s1[4][4] = {{'#', '#', '#', '.'}, {'#', '#', '#', '.'}, {'#', '#', '#', '.'}, {'.', '.', '.', '.'}};
char s2[4][4] = {{'.', '.', '.', '.'}, {'.', '#', '#', '#'}, {'.', '#', '#', '#'}, {'.', '#', '#', '#'}};
int main() {
    cin >> n >> m;
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cin >> a[i][j];
    for (int i=1;i<=n-8;i++) {
        for (int j=1;j<=m-8;j++) {
            bool flag = true;
            for (int dx=0;dx<4;dx++) {
                for (int dy=0;dy<4;dy++) {
                    if (a[i+dx][j+dy] != s1[dx][dy]) flag = false;
                }
                if (!flag) break;
            }
            if (!flag) continue;
            for (int dx=0;dx<4;dx++) {
                for (int dy=0;dy<4;dy++) {
                    if (a[i+5+dx][j+5+dy] != s2[dx][dy]) flag = false;
                }
                if (!flag) break;
            }
            if (flag) cout << i << ' ' << j << endl;
        }
    }
}