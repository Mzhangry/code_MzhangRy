// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;

int main() {
    struct Pa
    {
        int age;
        string id;
    };
    int n,numO=0;
    cin >> n;
    Pa a[105],old[105],tmp;
    for (int i=0;i<n;i++) cin >> a[i].id >> a[i].age;
    for (int i=0;i<n;i++) {
        if (a[i].age >= 60) {
            old[numO] = a[i];
            numO++;
        }
    }
    for (int i=0;i<numO-1;i++) {
        for (int j=0;j<numO-1;j++) {
            if (old[j].age < old[j+1].age) {
                tmp = old[j];
                old[j] = old[j+1];
                old[j+1] = tmp;
            }
        }
    }
    for (int i=0;i<numO;i++) cout << old[i].id << endl;
    for (int i=0;i<n;i++) if (a[i].age<60) cout << a[i].id << endl;
}