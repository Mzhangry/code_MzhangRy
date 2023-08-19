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
typedef pair<int, string> P;

struct TU
{
    char e[50][50];
    int w=40, h=40;
};

void csh (TU& a) {
    for (int i=0;i<=40;i++) for (int j=0;j<=40;j++) a.e[i][j] = '.';
}
P s[6];
P ins[6];
TU ans;
bool issmallerthanans (TU a) {
    for (int i=0;i<=40;i++) {
        for (int j=0;j<=40;j++) {
            if (a.e[i][j] < ans.e[i][j]) return true;
            else if (a.e[i][j] > ans.e[i][j]) return false;
        }
    }
    return false;
}
int main() {
    csh (ans);
    for (int i=0;i<6;i++) {
        cin >> ins[i].second;
        ins[i].first = ins[i].second.length();
    }
    sort(ins, ins+6);
    bool flag = false; // 最长的横放
    s[1] = ins[1]; s[0] = ins[0];
    for (int las1 = 2;las1<6;las1++) {
        for (int las2 = 2;las2<6;las2++) if (las1 != las2) {
            bool flag1 = false;
            for (int i=2;i<6;i++) {
                if (i != las1 && i != las2) {
                    if (flag1) s[2] = ins[i];
                    else {
                        s[3] = ins[i];
                        flag1 = true;
                    }
                }
            }
            s[4] = ins[las1]; s[5] = ins[las2];
            for (int cx = 1; cx<s[4].first-1; cx++) { // 枚举叉点
                for (int cy = 1;cy<s[5].first-1;cy++) {
                    if (s[5].second[cy] == s[4].second[cx]) { //叉点合法
                        for (int i=0;i<4;i++) if (s[i].first == cx+1 && s[i].second[s[i].first-1] == s[5].second[0]) { // 左上竖
                            for (int j=0;j<4;j++) if (j!=i && s[j].first == s[4].first - cx && s[j].second[0] == s[5].second[s[5].first-1]) { // 右下竖
                                for (int k=0;k<4;k++) if (k!=i && k!=j && s[k].first == cy+1 && s[k].second[0] == s[i].second[0] && s[k].second[s[k].first-1] == s[4].second[0]) { // 左上横
                                    for (int p=0;p<4;p++) if (p!=i && p!=j && p!=k && s[p].first == s[5].first - cy && s[p].second[0] == s[4].second[s[4].first-1] && s[p].second[s[p].first-1] == s[j].second[s[j].first-1]) { // 右下横
                                        flag = true;
                                        TU a; csh(a);
                                        int x = 0, y = 0;
                                        // 右下右
                                        for (char c : s[k].second) {
                                            a.e[x][y++] = c;
                                        } y--;
                                        for (char c : s[4].second) {
                                            a.e[x++][y] = c;
                                        } a.h = x; x--;
                                        for (char c : s[p].second) {
                                            a.e[x][y++] = c;
                                        } y--;
                                        // 下右下
                                        x = 0, y = 0;
                                        for (char c : s[i].second) {
                                            a.e[x++][y] = c;
                                        } x--;
                                        for (char c : s[5].second) {
                                            a.e[x][y++] = c;
                                        } a.w = y; y--;
                                        for (char c : s[j].second) {
                                            a.e[x++][y] = c;
                                        }
                                        // cout << 1;
                                        if (ans.e[0][0] == '.' || issmallerthanans(a)) ans = a;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (!flag) cout << "Impossible" << endl;
    else {
        if (ans.h > ans.w) swap(ans.h, ans.w);
        for (int i=0;i<ans.w;i++) {
            for (int j=0;j<ans.h;j++) {
                cout << ans.e[i][j];
            }
            cout << endl;
        }
    }
}