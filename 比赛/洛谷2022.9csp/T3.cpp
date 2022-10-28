// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

void bubblesort(int a[], int n) {
    for (int i=0;i<n-1;i++) {
        for (int j=0;j<n-1;j++) {
            if (a[j] > a[j+1]) swap(a[j], a[j+1]);
        }
    }
}
int main() {
    int n, x, p, q;
    double needsleep, sleep = 0, todaytime;
    cin >> n >> x >> p >> q;
    int day = 1;
    int task[100010];
    for (int i=0;i<n;i++) cin >> task[i];
    bubblesort(task, n);
    while (1) {
        needsleep = 1.0*p/q*x*day;
        todaytime = x - (needsleep - sleep);
        for (int i=0;i<n/2+1;i++) {
            int a = task[i];
            
        }
    }
}