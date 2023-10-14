#include<bits/stdc++.h>
using namespace std;
const int maxnode = 1000 + 10;
const int maxn = 200 + 10;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};
string s;
struct Node {
    int tp, id, ls, rs;
} tr[maxnode];
stack<int> nodestk;//node index
stack<int> opstk; // 1:( ,2:) ,3:or ,4:and ,5:not
int tot = 0, n, m, k, len;
bool g[maxn][maxn], a[30], f[maxnode];
int c[maxn][maxn];

void getnext(int & i, int & tp, int & id) {
    if (s[i] == '(') tp = 1;
    else if (s[i] == ')') tp = 2;
    else if (i + 1 < len && s.substr(i, 2) == "OR") tp = 3, i++;
    else if (i + 2 < len && s.substr(i, 3) == "AND") tp = 4, i+=2;
    else if (i + 2 < len && s.substr(i, 3) == "NOT") tp = 5, i+=2;
    else if (i + 3 < len && s.substr(i, 4) == "TRUE") tp = 0, id = 27, i+=3;
    else if (i + 4 < len && s.substr(i, 5) == "FALSE") tp = 0, id = 28, i+=4;
    else {
        tp = 0;
        id = s[i] - 'A' + 1;
    }
}

void treat() {
    if (opstk.top() == 5) {
        int x = nodestk.top(); nodestk.pop();
        tr[++tot] = {opstk.top(), 0, x, 0};
    } else {
        int x, y;
        y = nodestk.top(); nodestk.pop();
        x = nodestk.top(); nodestk.pop();
        tr[++tot] = {opstk.top(), 0, x, y};
    }
    opstk.pop();
    nodestk.push(tot);
}

bool priorer(int x, int y) {
    if (x != y) return x > y;
    return x == 3 || x == 4; //or 和 and 是左结合，not 是右结合
}

bool getval(int tp, bool x, bool y) {
    if (tp == 3) return x || y;
    if (tp == 4) return x && y;
    return ! x;
}

bool calc() {
    for (int i = 1; i <= tot; i++)
        if (!tr[i].tp) f[i] = a[tr[i].id];
        else f[i] = getval(tr[i].tp, f[tr[i].ls], f[tr[i].rs]);
    return f[tot];
}

int main() {
    getline(cin, s);
    len = s.size();
    for (int i = 0; i < len; i++)
        if (s[i] != ' ') {
            int tp, id;
            getnext(i, tp, id);
            if (tp == 0) {
                tr[++tot] = {0, id, 0, 0};
                nodestk.push(tot);
            } else {
                if (tp == 1) opstk.push(tp);
                else if (tp == 2) {
                    while (opstk.top() != 1) treat();
                    opstk.pop(); //弹出左括号
                } else {
                    while (opstk.size() && priorer(opstk.top(), tp)) treat();
                    opstk.push(tp);
                }
            }
        }
    while (opstk.size()) treat(); // tr[tot]    
    for (int i=1;i<=tot;i++) cout << i << ' ' << tr[i].tp << ' ' << tr[i].id << ' ' << tr[i].ls <<  ' ' << tr[i].rs << endl;

    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y; x += n; y += n;
        g[x][y] = true;
    }
    for (int i = 0; i < k; i++) {
        int x, y; char ch; cin >> x >> y >> ch; x += n; y += n;
        c[x][y] = ch - 'A' + 1;
    }

    a[27] = true; // a[1...28]   a[27]=true
    int x = n, y = n, dir = 0;  //(0,0)  +n +n   [0,0],[2n,2n]
    while (x >= 0 && x <= n * 2 && y >= 0 && y <= n * 2) {
        cout << x - n << ' ' << y - n << '\n';
        if (g[x][y]) {
            if (calc()) dir = (dir + 1) % 4;
            else dir = (dir - 1 + 4) % 4;
        }
        if (c[x][y]) a[c[x][y]] = !a[c[x][y]];
        x += dx[dir];
        y += dy[dir];
    }
    return 0;
}