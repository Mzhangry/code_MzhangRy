// MzhangRy - 张容钰
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

set<int> choice; 
int dfs (int k) {
    if (k == 7){
        if (choice.find(choice.size()) == choice.end()) return 0;
        set<int> B;
        for (int i=1;i<=6;i++) if (choice.find(i) == choice.end()) B.insert(i);
        if (B.find(B.size()) == B.end()) return 0;
        return 1;
    } 
    int ans = 0;
    ans += dfs (k+1);
    choice.insert(k);
    ans += dfs (k+1);
    choice.erase (k);
    return ans;
}
int main() {
    cout << dfs(1) << endl;
}