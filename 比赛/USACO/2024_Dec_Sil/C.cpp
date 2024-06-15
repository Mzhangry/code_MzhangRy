// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5 + 10;
int t, c;
bitset<2*maxn> target[11], en, preT;
int com[maxn], pre[4][maxn], f[2*maxn];
int pos = maxn;
struct Node
{
    int pos, cnt;
};
vector<Node> ve;
string s;
int ans = 0;
int main() {
    ios::sync_with_stdio(false);
    cin >> t >> c;
    for (int i=0;i<t;i++) {
        int a; cin >> a;
        en[a + maxn] = true;
    }
    cin >> s;
    for (int i=0;i<c;i++) {
        if (s[i] == 'L') com[i] = 1, pre[1][i] = i;
        else if (s[i] == 'R') com[i] = 2, pre[2][i] = i;
        else com[i] = 3, pre[3][i] = i;
        for (int j=1;j<=3;j++) pre[j][i+1] = pre[j][i];
    }

    for (int i=0;i<c;i++) {
        if (com[i] == 1) pos--;
        else if (com[i] == 2) pos++;
        else {
            target[3][pos] = 1;
            target[2][pos-1] = 1, target[1][pos-2] = 1;
            target[4][pos+1] = 1, target[5][pos+2] = 1;
        }
        if (com[i] == 3) f[pos]++;
    }

    for (int i=1;i<=5;i++) target[i] &= en;
    ans = target[3].count();

    pos = maxn;
    for (int i=0;i<c;i++) {
        if (com[i] == 3) {
            if (--f[pos] == 0) {
                target[3][pos] = 0; 
                target[2][pos-1] = 0, target[1][pos-2] = 0;
                target[4][pos+1] = 0, target[5][pos+2] = 0;
            }
        }

        if (com[i] == 2) {
            if (!preT[pos] && en[pos]) {
                preT[pos] = true;
                ans = max(ans, (int)(preT | target[2]).count());
                preT[pos] = false;
            }
            if (pre[3][i] >= pre[2][i-1]) ans = max (ans, (int)(preT | target[1]).count());
        } else if (com[i] == 1) {
            if (!preT[pos] && en[pos]) {
                preT[pos] = true;
                ans = max(ans, (int)(preT | target[4]).count());
                preT[pos] = false;
            }
            if (pre[3][i] >= pre[1][i-1]) ans = max (ans, (int)(preT | target[5]).count());
        } else {
            ans = max(ans, max((int)(preT | target[4]).count() , (int)(preT | target[2]).count()));
        }

        if (com[i] == 1) pos--;
        else if (com[i] == 2) pos++;
        else if (en[pos] == true) preT[pos] = true;
    }

    cout << ans << endl;
}