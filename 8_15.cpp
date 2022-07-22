// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int d1[10] = {-1,-1,0,1,1,1,0,-1},
    d2[10] = {0,1,1,1,0,-1,-1,-1};
int a[9][9],a1[9][9];
void fanzhi () {
    int x, y;
    for (int i=0;i<9;i++) for (int j=0;j<9;j++) a[i][j] = a1[i][j];
    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            for (int d=0;d<8;d++) {
                x = i+d1[d];
                y = j+d2[d];
                if (x>=0 && x<=8 && y>=0 && y<=8) a1[x][y] += a[i][j];
            }
            a1[i][j] += a[i][j];
        }
    }
}
int main() {
    cin >> a1[4][4];
    int n;
    cin >> n;
    for (int i=0;i<n;i++) fanzhi();
    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            cout << a1[i][j] << ' ';
        }
        cout << endl;
    }
}