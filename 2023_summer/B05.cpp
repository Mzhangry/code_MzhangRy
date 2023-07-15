// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

struct Twoxy{
    int x1, y1, x2, y2;
};
vector<Twoxy> ans;
int n;
char a[25][25];
int dx[4] = {1, 0, -1, 0},
    dy[4] = {0, 1, 0, -1};
bool vis[25][25];
void dfs (int stx, int sty, int edx, int edy, int x, int y) {
    vis[x][y] = true;
    for (int i=0;i<4;i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx >= stx && xx <= edx && yy >= sty && yy <= edy && a[xx][yy] == a[x][y] && !vis[xx][yy]) dfs (stx, sty, edx, edy, xx, yy);
    }
}

int main() {
    cin >> n;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cin >> a[i][j];
        }
    }

    for (int stx=1;stx<=n;stx++) { // (stx, sty) 为起点
        for (int sty=1;sty<=n;sty++) {
            for (int edx=stx;edx<=n;edx++) {
                for (int edy=sty;edy<=n;edy++) {
                    // 判断是否有且只有两种字符
                    char m1 = 0, m2 = 0;
                    bool flag1 = true;
                    for (int i=stx;i<=edx;i++) {
                        for (int j=sty;j<=edy;j++) {
                            if (m1 == 0) m1 = a[i][j];
                            else if (m2 == 0 && a[i][j] != m1) m2 = a[i][j];
                            else if (a[i][j] != m1 && a[i][j] != m2) {
                                flag1 = false;
                                break;
                            }
                        }
                        if (!flag1) break;
                    }
                    if (!flag1) continue;

                    int cnt1 = 0, cnt2 = 0;
                    memset (vis, 0, sizeof(vis));
                    for (int i=stx;i<=edx;i++) {
                        for (int j=sty;j<=edy;j++) {
                            if (!vis[i][j]) {
                                dfs (stx, sty, edx, edy, i, j);
                                if (a[i][j] == m1) cnt1++;
                                else cnt2++;
                            }
                        }
                    }
                    Twoxy d = {stx, sty, edx, edy};
                    if (cnt1==1 && cnt2>1 || cnt1>1 && cnt2==1) ans.push_back(d);
                }
            }
        }
    }
    // 判断是否已是存在的ans的子矩阵
    int cnt = 0;
    for (int i=0;i<ans.size();i++) {
        bool flag = true;
        for (int j=0;j<ans.size();j++) {
            if (i==j) continue;
            if (ans[i].x1 >= ans[j].x1 && ans[i].y1 >= ans[j].y1 && ans[i].x2 <= ans[j].x2 && ans[i].y2 <= ans[j].y2) {
                flag = false;
                break;
            }
        }
        if (flag == true) cnt++;
    }
    //for (int i=0;i<ans.size();i++) cout << ans[i].x1 << ' ' << ans[i].y1 << "  " << ans[i].x2 << ' ' << ans[i].y2 << endl;
    cout << cnt << endl;
}
