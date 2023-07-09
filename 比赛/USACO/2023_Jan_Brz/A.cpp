// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int e[100005];
char p[100005];
bool f[100005];
int main() {
    int n;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> p[i];
    for (int i=1;i<=n;i++) cin >> e[i];
    int sH, sG;
    bool sHis = false, sGis = false;
    for (int i=1;i<=n;i++) if (p[i] == 'H') {
        sH = i;
        break;
    }
    for (int i=1;i<=n;i++) if (p[i] == 'G') {
        sG = i;
        break;
    }

    int cntG = 0;
    for (int i=n;i>=1;i--) if (p[i] == 'H') {
        if (e[sH] >= i) { // sH是领头
            sHis = true;
            for (int j=1;j<sH;j++) {
                if (p[j] == 'G' && e[j] >= sH) cntG++;
            }
        }
        break;
    }
    int cntH = 0;
    for (int i=n;i>=1;i--) if (p[i] == 'G') {
        if (e[sG] >= i) {
            sGis = true;
            for (int j=1;j<sG;j++) {
                if (p[j] == 'H' && e[j] >= sG) cntH++;
            }
        }
        break;
    }
    if (sGis && sHis) {
        if (sG < sH && e[sG] < sH) cntG++;
        else if (sH < sG && e[sH] < sG) cntH++;
    }
    cout << cntG + cntH << endl;
    return 0;
}