// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
    ll x, y;
} st, ed, pos;
ll culc_dis (Node a, Node b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}
int main() {
    cin >> pos.x >> pos.y >> st.x >> st.y >> ed.x >> ed.y;
    vector<Node> target;
    ll gotost = 1e18, gotoend = 1e18;
    ll ans = 0;
    if (st.x == ed.x) {
        if (st.y < ed.y) {target.push_back({st.x, st.y-1}); if (pos.x == st.x && pos.y > st.y) ans += 2;}
        else {target.push_back({st.x, st.y+1}); if (pos.x == st.x && pos.y < st.y) ans += 2;}
        ans += culc_dis(pos, target[0]) + culc_dis(st, ed);
    } else if (st.y == ed.y) {
        if (st.x < ed.x) {target.push_back({st.x - 1, st.y}); if (pos.y == st.y && pos.x > st.x) ans += 2;}
        else {target.push_back({st.x + 1, st.y}); if (pos.y == st.y && pos.x < st.x) ans += 2;}
        ans += culc_dis(pos, target[0]) + culc_dis(st, ed);
    } else {
        target.resize(2);
        if (st.x < ed.x && st.y < ed.y) target[0] = {st.x - 1, st.y}, target[1] = {st.x, st.y-1};
        else if (st.x < ed.x && st.y > ed.y) target[0] = {st.x - 1, st.y}, target[1] = {st.x, st.y+1};
        else if (st.x > ed.x && st.y < ed.y) target[0] = {st.x + 1, st.y}, target[1] = {st.x, st.y-1};
        else target[0] = {st.x + 1, st.y}, target[1] = {st.x, st.y+1};
        ans = min(culc_dis(pos, target[0]), culc_dis(pos, target[1])) + culc_dis(st, ed) + 2;
    }
    cout << ans << endl;
}