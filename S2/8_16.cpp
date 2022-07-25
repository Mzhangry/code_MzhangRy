// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int d1[5] = {1,-1,0,0}, 
    d2[5] = {0,0,-1,1};
char a0[105][105], a[105][105];
int n,m, d;

void fight() {
    int x,y;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            a0[i][j] = a[i][j];
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            for (int d=0;d<4;d++) {
                x = i+d1[d];
                y = j+d2[d];
                if (a0[x][y] == 'R' && a0[i][j] == 'P') a[x][y] = 'P';
                else if (a0[x][y] == 'S' && a0[i][j] == 'R') a[x][y] = 'R';
                else if (a0[x][y] == 'P' && a0[i][j] == 'S') a[x][y] = 'S';
            }
        }
    }
}
int main() {
    cin >> n >> m >> d;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> a[i][j];
        }
    }
    for (int i=0;i<d;i++) fight();
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
}