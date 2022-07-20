// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    struct Student
    {
        int c,m,e,sum,id;
    };
    Student a[305], tmp;
    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> a[i].c >> a[i].m >> a[i].e;
        a[i].sum = a[i].c + a[i].m + a[i].e;
        a[i].id = i+1;
    }
    for (int i=0;i<n-1;i++) {
        for (int j=0;j<n-1;j++) {
            if (a[j].sum < a[j+1].sum || 
            a[j].sum == a[j+1].sum && (a[j].c < a[j+1].c || 
            a[j].c == a[j+1].c && a[j].id > a[j+1].id) ) {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
    for (int i=0;i<5;i++) cout << a[i].id << ' ' << a[i].sum << endl;
}