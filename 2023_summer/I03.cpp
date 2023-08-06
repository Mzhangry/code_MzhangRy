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

char e[9][9];
int stx, sty;
int main() {
    for (int i=0;i<9;i++) for (int j=0;j<9;j++) cin >> e[i][j];
    cin >> stx >> sty; stx--; sty--;
    while (stx > 2) stx -= 3;
    while (sty > 2) sty -= 3;
    int fx, fy;
    fx = stx * 3, fy = sty * 3;
    bool flag = false;
    for (int i=fx;i<fx+3;i++) {
        for (int j=fy;j<fy+3;j++) {
            if (e[i][j] == '.') {
                flag = true;
                e[i][j] = '!';
            }
        }
    }
    if (!flag) {
        for (int i=0;i<9;i++) {
            for (int j=0;j<9;j++) {
                if (e[i][j] == '.') e[i][j] = '!';
            }
        }
    }
    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            cout << e[i][j];
            if ((j+1) % 3 == 0) cout << ' ';
        }
        cout << endl;
        if ((i+1) % 3 == 0) cout << endl;
    }
}