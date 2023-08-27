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
struct XY {
    int x, y;
};

int h, w;
XY st, ed;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int main() {
    cin >> h >> w;
    vector< vector<char> > e(h+2, vector<char>(w+2, '#'));
    vector< vector<bool> > check(h+2, vector<bool>(w+2, 0)), vis(h+2, vector<bool>(w+2, 0));
    vector< vector<int> > dis(h+2, vector<int>(w+2, 0));
    for (int i=1;i<=h;i++) {
        for (int j=1;j<=w;j++) {
            cin >> e[i][j];
            if (e[i][j] == 'S') st = {i, j};
            if (e[i][j] == 'G') ed = {i, j};
        }
    }
    for (int i=1;i<=h;i++) {
        bool flag = false;
        for (int j=1;j<=w;j++) {
            if (e[i][j] == '>') {
                flag = true;
            } else if (e[i][j] == '#' || e[i][j] == '<' || e[i][j] == '^' || e[i][j] == 'v') {
                flag = false;
            } else if (flag == true) {
                check[i][j] = true;
            }
        }
    }

    for (int j=1;j<=w;j++) {
        bool flag = false;
        for (int i=1;i<=h;i++) {
            if (e[i][j] == 'v') {
                flag = true;
            } else if (e[i][j] == '#' || e[i][j] == '<' || e[i][j] == '^' || e[i][j] == '>') {
                flag = false;
            } else if (flag == true) {
                check[i][j] = true;
            }
        }
    }

    for (int i=1;i<=h;i++) {
        bool flag = false;
        for (int j=w;j>=1;j--) {
            if (e[i][j] == '<') {
                flag = true;
            } else if (e[i][j] == '#' || e[i][j] == '>' || e[i][j] == '^' || e[i][j] == 'v') {
                flag = false;
            } else if (flag == true) {
                check[i][j] = true;
            }
        }
    }

    for (int j=1;j<=w;j++) {
        bool flag = false;
        for (int i=h;i>=1;i--) {
            if (e[i][j] == '^') {
                flag = true;
            } else if (e[i][j] == '#' || e[i][j] == '<' || e[i][j] == '>' || e[i][j] == 'v') {
                flag = false;
            } else if (flag == true) {
                check[i][j] = true;
            }
        }
    }

    for (int i=1;i<=h;i++) {
        for (int j=1;j<=w;j++) {
            if (check[i][j] == true || e[i][j] == '>' || e[i][j] == '<' || e[i][j] == '^' || e[i][j] == 'v') {
                e[i][j] = '#';
            }
        }
    }

    queue<XY> q;
    q.push(st); vis[st.x][st.y] = true;
    while (!q.empty()) {
        XY d = q.front(); q.pop();
        if (d.x == ed.x && d.y == ed.y) {
            break;
        }
        for (int i=0;i<4;i++) {
            int nx = d.x + dx[i], ny = d.y + dy[i];
            if (nx >= 1 && nx <= h && ny >= 1 && ny <= w && vis[nx][ny] == false && e[nx][ny] != '#') {
                vis[nx][ny] = true;
                dis[nx][ny] = dis[d.x][d.y] + 1;
                q.push({nx, ny});
            }
        }
    }

    if (vis[ed.x][ed.y] == false) {
        cout << -1 << endl;
    } else {
        cout << dis[ed.x][ed.y] << endl;
    }
}