// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
struct Zone
{
    int sum = 0, need;
    bool num[10];
    int lasx, lasy;
    //vector<int> checkx, checky;
};
struct Check
{
    int kind; // 1为白 2为灰
    int numa = -1, numb = -1; 
    int zonea = -1, zoneb = -1;
};

int n, m;
int numza = 0, numzb = 0;
Zone za[300], zb[300];
Check e[20][20];
int board[20][20];

void dfs (int x, int y) {
    if (x > m) {
        // bool flag = true;
        // for (int z = 1; z<=numza; z++) {
        //     if (za[z].sum != za[z].need){
        //         flag = false;
        //         break;
        //     }
        // }
        // if (!flag) return;
        // for (int z = 1; z<=numzb; z++) {
        //     if (zb[z].sum != zb[z].need) {
        //         flag = false;
        //         break;
        //     }
        // }
        // if (!flag) return;
        for (int i=1;i<=m;i++) {
            for (int j=1;j<=n;j++) {
                if (board[i][j] == -1) cout << '_' << ' ';
                else cout << board[i][j] << ' ';
            }
            cout << endl;
        }
        exit(0);
    }
    if (board[x][y] == -1) {
        if (y == n) dfs(x+1, 1);
        else dfs (x, y+1);
        return;
    }
    for (int i=1;i<=9;i++) {
        //cout << x <<  ' ' << y << "  " << i << endl;
        Zone &a = za[e[x][y].zonea], &b = zb[e[x][y].zoneb];
        if (a.num[i] || b.num[i]) continue;
        // cout << a.need<< ' ' << a.sum << ' ' << b.need << ' ' << b.sum;
        if (a.sum + i > a.need || b.sum + i > b.need) return;
        board[x][y] = i;
        a.num[i] = true; b.num[i] = true;
        a.sum += i; b.sum += i;
        bool flag = true;
        if (x == a.lasx && y == a.lasy && a.sum != a.need) flag = false;
        if (x == b.lasx && y == b.lasy && b.sum != b.need) flag = false; 
        //cout << x <<  ' ' << y << "  " << i << endl;
        if (flag) {
            if (y == n) dfs(x+1, 1);
            else dfs (x, y+1);
        }
        a.num[i] = false; b.num[i] = false;
        a.sum -= i; b.sum -= i;
    }
}

int main() {
    // freopen ("C06.out", "w", stdout);
    cin >> m >> n;
    for (int i=1;i<=m;i++) { //读入
        for (int j=1;j<=n;j++) {
            cin >> e[i][j].kind;
            if (e[i][j].kind == 2) {
                cin >> e[i][j].numa >> e[i][j].numb;
                board[i][j] = -1;
            }
        }
    }
    for (int i=1;i<=m;i++) { //划分区域
        for (int j=1;j<=n;j++) {
            if (e[i][j].kind == 1) {
                if (e[i][j-1].kind == 2) {
                    e[i][j].zoneb = ++numzb;
                    zb[numzb].need = e[i][j-1].numb;
                    zb[numzb].lasx = i; zb[numzb].lasy = j;
                    //za[numza].checkx.push_back(i); za[numza].checky.push_back(j);
                }
                else {
                    e[i][j].zoneb = e[i][j-1].zoneb;
                    zb[e[i][j].zoneb].lasx = i; zb[e[i][j].zoneb].lasy = j;
                }
                if (e[i-1][j].kind == 2) {
                    e[i][j].zonea = ++numza;
                    //cout << '&' << e[i-1][j].numa << endl;
                    za[numza].need = e[i-1][j].numa;
                    za[numza].lasx = i; za[numza].lasy = j;
                }
                else {
                    e[i][j].zonea = e[i-1][j].zonea;
                    za[e[i][j].zonea].lasx = i; za[e[i][j].zonea].lasy = j;
                }
            }
        }
    }
    for (int i=1;i<=numza;i++) memset (za[i].num, 0, sizeof(za[i].num));
    for (int i=1;i<=numzb;i++) memset (zb[i].num, 0, sizeof(zb[i].num));
    // for (int i=1;i<=numza;i++) cout << '&' << za[i].lasx << ' ' << za[i].lasy << endl;
    // for (int i=1;i<=numza;i++) cout << "// a:need //\n" << za[i].need<< ' ';
    // for (int i=1;i<=m;i++) {
    //     for (int j=1;j<=n;j++) {
    //         cout << e[i][j].zonea << ' ';
    //     }
    //     cout << endl;
    // }
    dfs (1, 1);
}