#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
#define ls(p) (p << 1)
#define rs(p) (p << 1 | 1)
#define mx(p) mx[p]
#define tail(p) tree[p].tail
const ll inf = 2e9+11;
#define mid ((pl + pr) >> 1)

ll m, mod;
const int maxn = 2e5+10;
ll cnt = 0, t = 0, num = 0;
ll mx[maxn << 2];
void update (int p) {
	mx(p) = max(mx(ls(p)) , mx(rs(p))); 
	return; 
}
void myinsert (int p, int pl, int pr, ll d) {
	if (pl == pr) {
		mx(p) =  (t + d) % mod;
		return;
	}
	if (num <= mid) myinsert (ls(p), pl, mid, d);
	else myinsert (rs(p), mid+1, pr, d);
	update (p); return;
}
ll query(int p, int pl, int pr, int dl, int dr) {
	if (dl <= pl && dr >= pr) return mx(p);
    ll t = -inf;
    if (dl <= mid) t = max(t, query(ls(p), pl, mid, dl, mid));
    if (mid < dr) t = max(t, query(rs(p), mid+1, pr, dl, dr));
    return t;
}
int main () {
    ios::sync_with_stdio(false); 
    cin >> m >> mod;
    for (int i=1;i<=m;i++) {
    	char c; ll d; 
        do{
            cin >> c;
        }while(c != 'A' && c != 'Q');
        cin >> d;
    	if (c == 'Q') {
            if (d == 0) t=0;
    		else t = query(1, 1, m, num-d+1, m);
    		cout << t << endl;
		} else {
            num++;
			myinsert (1, 1, m, d);
		}
	}
}