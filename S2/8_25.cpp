// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int n,m, nextx = 0, nexty = 0;
int a[25][25];
int dx[5] = {0,1,0,-1}, // 方向数组
    dy[5] = {1,0,-1,0};

int main() {
    string s; // 下标为1 ~ len-1
    cin >> n >> m;
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) a[i][j] = -1;
    getline (cin, s);
    int cnt = 0, y[10];
    int d = 0; // 当前方向，对应 dx 和 dy
    for (int i=1;i<s.length();i++) {
        // 转换为二进制 y[4] ~ y[0]
        int x;
        if (s[i] == ' ') x = 0;
        else x = s[i] - 'A' + 1;
        for (int j=0;j<5;j++) {
            y[j] = x % 2;
            x /= 2;
        }
        // 填入
        for (int j=4;j>=0;j--) {
            a[nextx][nexty] = y[j];
            // 计算下一个位置
            int nextx1 = nextx + dx[d];
            int nexty1 = nexty + dy[d];
            // 超界啦！转弯！
            if (nextx1 < 0 || nextx1 >= n || nexty1 < 0 || nexty1 >=m || a[nextx1][nexty1] != -1) {
                d = (d+1) % 4;
                nextx = nextx + dx[d];
                nexty = nexty + dy[d];
            } else {
                nextx = nextx1;
                nexty = nexty1;
            }
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (a[i][j] == -1) cout << 0;
            else cout << a[i][j];
        }
    }
}