// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

struct Task
{
    int p, t;
    bool operator < (const Task & r) const {
        return p < r.p;
    }
};
Task task[10005];
int mxnum = 100000;
int f[1005];
int nowtask = 0;
int main() {
    int n, k;
    cin >> n >> k;
    for (int i=1;i<=n;i++) f[i] = mxnum;
    for (int i=0;i<k;i++) cin >> task[i].p >> task[i].t;
    sort (task, task + k);
    int num = 0;
    for (int i=1;i<=n;i++) {
        if (num != mxnum) {
            bool flag = false;
            for (;task[nowtask].p == i; nowtask++) {
                f[i+task[nowtask].t-1] = min(num + task[nowtask].t, f[i+task[nowtask].t-1]);
                flag = true;
            }
            if (flag) num = mxnum;
        }
        num = min(num, f[i]);
    }
   // for (int i=1;i<=n;i++) cout << f[i] << ' ';
    //cout << endl;
    cout << n-num;
}
//不应该讲 == 0 ？分开