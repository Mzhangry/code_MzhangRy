#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
vector<int> s;
vector< vector<int> > e;
vector<int> orbit;
int fid (int a) {
    if (s[a] == a) return a;
    s[a] = fid(s[a]);
    return s[a];
}
void merge (int a, int b) {
    a = fid(a), b = fid(b);
    if (a != b) s[a] = b;
}
bool dfs(int a, int o) {
    if (o == 1 && fid(a) == fid(n) || o == n && fid(a) == fid(1)) return true;
    if (orbit[a] && orbit[a] != o) return false;
    if (orbit[a] == 0) orbit[a] = o;
    for (int d : e[a]) {
        if (o != orbit[d] && dfs(d, o)) return true;
    }
    e[a].clear();
    return false;
}


int main() {
    cin >> n >> m;
    s.resize(n+1); e.resize(n+1); orbit.resize(n+1);
    for (int i=1;i<=n;i++) s[i] = i; 
    orbit[1] = 1, orbit[n] = n;

    string s; getline(cin, s);
    for  (int i=1;i<=m;i++) {
        int a, b; char c;
        scanf("\nA%d %c A%d", &a, &c, &b);
        if (c == '='){
            merge(a, b); if (fid(1) == fid(n)) {cout << i << endl; return 0;}
            e[a].push_back(b);
            if ((orbit[a] == n || orbit[a] == 1) && dfs(a, orbit[a])) {cout << i << endl; return 0;}
            e[b].push_back(a);
            if ((orbit[b] == n || orbit[b] == 1) && dfs(b, orbit[b])) {cout << i << endl; return 0;}
        } else {
            e[a].push_back(b);
            if ((orbit[a] == 1 || orbit[a] == n) && dfs(a, orbit[a])) {cout << i << endl; return 0;}
        }
    }
    cout << -1 << endl;
}
