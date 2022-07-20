// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    struct People
    {
        int id,s;
    };
    int n,m,num=0;
    People a[5005],tmp;
    cin >> n >> m;
    for (int i=0;i<n;i++) cin >> a[i].id >> a[i].s;
    for (int i=0;i<n-1;i++) {
        for (int j=0;j<n-1;j++) {
            if (a[j].s < a[j+1].s || a[j].s == a[j+1].s && a[j].id > a[j+1].id) {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
    int line = a[int((1.5*m))-1].s;
    for (int i=0;i<n;i++) {
        if (a[i].s >= line) {
            num ++;
        } else break;
    }
    cout << line << ' ' << num << endl;
    for (int i=0;i<num;i++) cout << a[i].id << ' ' << a[i].s << endl;
}