// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

bool a[200][200], b[15][15], c[100][100];
int main() {
    //freopen("A06.in", "r", stdin);
    //freopen("A06.out", "w", stdout);
    int ha, wa, hb, wb, hc, wc; // 读入abc 其中b从0,0开始 ac从40,40开始
    cin >> ha >> wa;
    for (int i=40;i<ha+40;i++) {
        for (int j=40;j<wa+40;j++) {
            char d; cin >> d;
            if (d == '#') a[i][j] = true;
        }
    }
    cin >> hb >> wb;
    for (int i=0;i<hb;i++) {
        for (int j=0;j<wb;j++) {
            char d; cin >> d;
            if (d == '#') b[i][j] = true;
        }
    }
    int stcx = 0, stcy = 0; // 存储c中第一个黑
    cin >> hc >> wc;
    for (int i=40;i<hc+40;i++) {
        for (int j=40;j<wc+40;j++) {
            char d; cin >> d;
            if (d == '#') c[i][j] = true;
            if (stcx == 0 && d=='#') {
                stcx = i; stcy = j;
            }
        }
    }
    bool m[200][200];
    memcpy(m, a, sizeof(a));
    //
    for (int xb=19;xb<=51;xb++) { //xb, yb为b[0][0]在a中所在位置
        for (int yb=19;yb<=51;yb++) {
            for (int i=0;i<hb;i++) { // 将b添加到a图中
                for (int j=0;j<wb;j++) {
                    if (b[i][j]) a[xb+i][yb+j] = true;
                }
            }
            bool flag1 = false;
            int stx = 80, sty = 80; // stx, sty为a图中第一个黑
            for (int i=19;i<80;i++) {
                for (int j=19;j<80;j++) {
                    if (a[i][j]) {
                        stx = i; sty = j;
                        flag1 = true;
                        break;
                    }
                }
                if (flag1) break;
            }

            bool flag = true; // comp a+b,c
            for (int i=-40;i<41;i++) {
                for (int j=-40;j<41;j++) {
                    int ax = stx + i, ay = sty + j;
                    int cx = stcx + i, cy = stcy + j;
                    if (ax < 0 || ay < 0 || cx < 0 || cy < 0) continue;
                    // cout << ax << ' ' << ay << ' ' << ' ' << cx << ' ' << cy << endl;
                    if (a[ax][ay] != c[cx][cy]) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) break;
            }

            if (flag) {
                // cout << xb << ' ' << yb << endl;
                cout << "Yes" << endl;
                return 0;
            }


            memcpy(a, m, sizeof(m)); //还原a
        }
    }
    cout << "No" << endl; 
    return 0;
}