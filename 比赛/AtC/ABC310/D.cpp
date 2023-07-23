// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int n, t, m;
bool con[15][15];
bool e[15][15];
int f(int x, int y){
    e[x][y] = true;
    if (x == n) return 1;
    
} // f[i][j] 第i个人放在第j队的方案数
int main() {
    cin >> n >> t >> m;
    for (int i=0;i<m;i++) {
        int a, b; cin >> a >> b;
        con[a][b] = true;
        con[b][a] = true;
    }
    
}