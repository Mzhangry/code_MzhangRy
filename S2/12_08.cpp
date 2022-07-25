// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    string s;
    double t;
    int c,n,cnt = 0;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> s >> t >> c;
        if (t >= 37.5 && c) {
            cout << s << endl;
            cnt ++;
        }
    }
    cout << cnt;
}