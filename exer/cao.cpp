// MzhangRy - 张容钰
#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int a[105][105], f[105][105];
const int minf = -1e5 - 10;
// f[i][j] 表示前i根草放在前j瓶，且第i个放在j瓶 的最大美学值
int main() {
    int c, v;
    cin >> c >> v;
    for (int i=1;i<=c;i++) 
        for (int j=1;j<=v;j++) 
            cin >> a[i][j];
  
    for (int i=1;i<=c;i++) {
   			for (int j=i;j<=v-c+i;j++) { // 至少剩下c-i个瓶子
    	  		f[i][j] = minf; // 因为美学值可能为负，要赋初始值
       			for (int k=i-1;k<=j-1;k++) {
            		f[i][j] = max(f[i][j], f[i-1][k] + a[i][j]);
        		}
   		 	}
		}
    int ans = minf, pos;
    for (int i=c;i<=v;i++) {
        if (f[c][i] > ans) {
            ans = f[c][i];
            pos = i;
        }
    }
    cout << ans << endl;

    vector<int> sch; // 用数组也可以啦
    for (int i=c;i>=1;i--) {
        sch.push_back(pos);
        for (int j=pos-1;j>=1;j--) {
            if (f[i][pos] == f[i-1][j] + a[i][pos]) {
                pos = j;
                break; // 随意一组方案 这里直接break掉就可以
            }
        }
    }
    for (int i=sch.size()-1;i>=0;i--) cout << sch[i] << ' ';
    cout << endl;
}