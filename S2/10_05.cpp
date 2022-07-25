// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    struct Student
    {
        string name;
        int s;
    };
    Student a[25], tmp;
    int n;
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i].name >> a[i].s;
    for (int i=0;i<n-1;i++) {
        for (int j=0;j<n-1;j++) {
            if (a[j].s < a[j+1].s || a[j].s == a[j+1].s && a[j].name > a[j+1].name) {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
    for (int i=0;i<n;i++) {
        cout << a[i].name << ' ' << a[i].s << endl;
    }
}