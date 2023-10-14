#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int read() {
    int x = 0, w = 1;
    char c = 0;
    while (c < '0' || c > '9') {
        if (c == '-') w = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x * w;
}
string s;
int n, m, k;
int len;
int e[210][210];
bool f[40]; // 1-26 27T 28F

struct Node {
    int tp, d, l, r; // 0 op 1 token
};
vector<Node> jd;
stack<int> nodestk, opstk;
void getnext(int& i, int& tp, int& d) {
    if (s[i] == '(') {tp = 0; d = 1; return;}
    else if (s[i] == ')') {tp = 0; d = 2; return;}
    else if (i + 1 < len && s.substr(i, 2) == "OR") {i += 1; tp = 0; d = 3; return;}
    else if (i + 2 < len && s.substr(i, 3) == "AND") {i += 2; tp = 0; d = 4; return;}
    else if (i + 2 < len && s.substr(i, 3) == "NOT") {i += 2; tp = 0; d = 5; return;}
    else if (i + 3 < len && s.substr(i, 4) == "TRUE") {i += 3; tp = 1; d = 27; return;}
    else if (i + 4 < len && s.substr(i, 5) == "FALSE") {i += 4; tp = 1; d = 28; return;}
    else {tp = 1; d = s[i] - 'A' + 1; return;}
}
void treat() {
    int t = opstk.top(); opstk.pop();
    int a = nodestk.top(); nodestk.pop();
    if (t == 5) jd.push_back({0, 5, a, 0});
    else {
        int b = nodestk.top(); nodestk.pop();
        jd.push_back({0, t, b, a});
    }
    nodestk.push(jd.size()-1);
}
bool priorer (int d) {
    if (opstk.top() != d) return opstk.top() > d;
    else return d == 3 || d == 4;
}
int dx[4] = {0, 1, 0, -1},
    dy[4] = {1, 0, -1, 0};

vector<bool> fx;
bool getvalue (Node p) {
    if (p.tp == 1) return f[p.d];
    if (p.d == 3) return fx[p.l] || fx[p.r];
    else if (p.d == 4) return fx[p.l] && fx[p.r];
    else return !fx[p.l];
}
bool cul() {
    fx.resize(jd.size()+1);
    for (int i=0;i<jd.size();i++) {
        Node p = jd[i];
        fx[i] = getvalue(p);
    }
    // cout << '@'; for (int i=0;i<jd.size();i++) cout << (int)fx[i] << ' '; cout << endl;
    return fx[jd.size()-1];
}
int main() {
    // freopen("D.in", "r", stdin);
    f[27] = true; // TRUE
    getline(cin, s);
    // n = read(), m = read(), k = read();
    // for (int i=0;i<m;i++) {
    //     int x = read() + n, y = read() + n;
    //     e[x][y] = -1;
    // }
    
    // for (int i=0;i<k;i++) {
    //     int x = read() + n, y = read() + n; char c; cin >> c;
    //     e[x][y] = c - 'A' + 1;
    // }

    len = s.length();
    for (int i=0;i<s.length();i++) {
        if (s[i] != ' ') { // token
            int tp, d; // tp: 1 Node 0 op
            getnext(i, tp, d);
            if (tp == 1) {jd.push_back({1, d, 0, 0}); nodestk.push(jd.size()-1);}
            else {
                if (d == 1) opstk.push(d);
                else if (d == 2) { // )
                    while (!opstk.empty() && opstk.top() != 1) treat();
                    opstk.pop(); // (
                } else {
                    while (!opstk.empty() && priorer (d) ) treat();
                    opstk.push(d);
                }
            }
        }
    }
    while (!opstk.empty()) treat();

    for (int i=0;i<jd.size();i++) cout << i << ' ' << jd[i].tp << ' ' << jd[i].d << ' ' << jd[i].l << ' ' << jd[i].r << endl;
    
    int dir = 1, x = n, y = n;
    while (x >= 0 && x <= 2*n && y >= 0 && y <= 2*n) {
        cout << x-n << ' ' << y-n << endl;
        if (e[x][y] == -1) { // turn
            // cout << (cul() ? "*Y*" : "*N*");
            if (cul()) dir = (dir + 1) % 4;
            else dir = (dir - 1 + 4) % 4;
        } else if (e[x][y] > 0) {
            f[e[x][y]] = !f[e[x][y]];
        }
        x += dx[dir], y += dy[dir];
    }
}

