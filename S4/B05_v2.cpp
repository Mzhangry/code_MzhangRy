// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int t;
char a[20][20];
int dx[5] = {0, 1, 1, 1},
    dy[5] = {1, 0, 1, -1};
bool hefa (int a,int b) {
    return a>=1 && a<=15 && b>=1 && b<=15;
}
bool check (char c) {
    for (int i=1;i<=15;i++) {
        for (int j=1;j<=15;j++) {
            for (int d=0;d<4;d++) {
                bool flag = true;
                for (int len=0;len<5;len++) {
                    int x = i + len*dx[d], y = j + len*dy[d];
                    if (!hefa(x,y) || a[x][y] != c) {
                        flag = false;
                    }
                }
                if (flag) return true;
            }
        }
    }
    return false;
}
int main() {
    cin >> t;
    while (t--) {
        for (int i=1;i<=15;i++) {
            for (int j=1;j<=15;j++) {
                cin >> a[i][j];
            }
        }
        if (check('W') && check('B')) cout << "Both" << endl;
        else if (check('W')) cout << "White" << endl;
        else if (check('B')) cout << "Black" << endl;
        else cout << "None" << endl;
    }
}