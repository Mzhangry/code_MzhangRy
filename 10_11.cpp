// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    struct People
    {
        string x;
        double h;
    };
    People a[45], tmp;
    int n;
    cin >> n;

    for (int i=0;i<n;i++) cin >> a[i].x >> a[i].h;
    for (int i=0;i<n-1;i++) {
        for (int j=0;j<n-1;j++) {
            if (a[j].h > a[j+1].h) {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
    for (int i=0;i<n;i++) if (a[i].x == "male") cout << fixed << setprecision(2) << a[i].h << ' ';
    for (int i=n-1;i>=0;i--) if (a[i].x == "female") cout << fixed << setprecision(2) << a[i].h << ' ';
}