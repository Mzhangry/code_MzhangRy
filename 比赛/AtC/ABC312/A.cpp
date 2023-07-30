// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;

string s;
string a[10] = {"ACE", "BDF", "CEG", "DFA", "EGB", "FAC", "GBD"};
int main() {
    cin >> s;
    for (int i=0;i<7;i++) {
        if (s == a[i]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}