// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    struct Student
    {
        string name,x;
        int g;
    };
    Student a[105], tmp;
    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> a[i].name >> a[i].g >> a[i].x;
    }
    for (int i=0;i<n-1;i++) {
        for (int j=0;j<n-1;j++) {
            if (a[j].g > a[j+1].g || (a[j].g == a[j+1].g && a[j].name > a[j+1].name)) {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
    for (int i=0;i<n;i++) cout << a[i].name << ' ' << a[i].g << ' ' << a[i].x << endl;
}