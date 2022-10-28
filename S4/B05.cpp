// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int t;
char a[20][20];
int b[20][20][8], w[20][20][8]; // 0up 1down 2left 3right 4ul 5ur 6dl 7dr
int main() {
    cin >> t;
    while (t--) {
        for (int i=1;i<=15;i++) {
            for (int j=1;j<=15;j++) {
                for (int d=0;d<=8;d++) {
                    b[i][j][d] = 0;
                    w[i][j][d] = 0;
                }
            }
        }
        for (int i=1;i<=15;i++) {
            for (int j=1;j<=15;j++) {
                cin >> a[i][j];
            }
        }
        for (int i=1;i<=15;i++) {
            for (int j=1;j<=15;j++) {
                if (a[i][j] == 'B') {
                    b[i][j][0] = b[i-1][j][0] + 1;
                    b[i][j][2] = b[i][j-1][2] + 1;
                    b[i][j][4] = b[i-1][j-1][4] + 1;
                } else if (a[i][j] == 'W') {
                    w[i][j][0] = w[i-1][j][0] + 1;
                    w[i][j][2] = w[i][j-1][2] + 1;
                    w[i][j][4] = w[i-1][j-1][4] + 1;
                }
            }
        }
        for (int i=15;i>=1;i--) {
            for (int j=15;j>=1;j--) {
                if (a[i][j] == 'B') {
                    b[i][j][1] = b[i+1][j][1] + 1;
                    b[i][j][3] = b[i][j+1][3] + 1;
                    b[i][j][7] = b[i+1][j+1][7] + 1;
                } else if (a[i][j] == 'W') {
                    w[i][j][1] = w[i+1][j][1] + 1;
                    w[i][j][3] = w[i][j+1][3] + 1;
                    w[i][j][7] = w[i+1][j+1][7] + 1;
                }
            }
        }
        for (int i=1;i<=15;i++) {
            for (int j=15;j>=1;j--) {
                if (a[i][j] == 'B') {
                    b[i][j][5] = b[i-1][j+1][5] + 1;
                } else if (a[i][j] == 'W') {
                    w[i][j][5] = w[i-1][j+1][5] + 1;
                }
            }
        }
        for (int i=15;i>=1;i--) {
            for (int j=1;j<=15;j++) {
                if (a[i][j] == 'B') {
                    b[i][j][6] = b[i+1][j-1][6] + 1;
                } else if (a[i][j] == 'W') {
                    w[i][j][6] = w[i+1][j-1][6] + 1;
                }
            }
        }
        bool ansb = false, answ = false;
        for (int i=1;i<=15;i++) {
            for (int j=1;j<=15;j++) {
                if (b[i][j][0] >= 3 && b[i][j][1] >= 3) ansb = true;
                else if (b[i][j][2] >= 3 && b[i][j][3] >=3) ansb = true;
                else if (b[i][j][4] >= 3 && b[i][j][7] >=3) ansb = true;
                else if (b[i][j][5] >= 3 && b[i][j][6] >=3) ansb = true;
                if (w[i][j][0] >= 3 && w[i][j][1] >= 3) answ = true;
                else if (w[i][j][2] >= 3 && w[i][j][3] >=3) answ = true;
                else if (w[i][j][4] >= 3 && w[i][j][7] >=3) answ = true;
                else if (w[i][j][5] >= 3 && w[i][j][6] >=3) answ = true;
            }
        }
        if (ansb && answ) cout << "Both" << endl;
        else if (ansb) cout << "Black" << endl;
        else if (answ) cout << "White" << endl;
        else cout << "None" << endl;
    }
}