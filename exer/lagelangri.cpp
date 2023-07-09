#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

void enter(vector<pair<double, double> > &x)  //录入信息
{
	do{
		static int n = 0;
		cout << "是否输入第" << n + 1 << "组数据,Y继续输入，N退出输入数据" << endl;
		string u;
		cin >> u;
		if (u == "Y")
		{
			n++;
			double dx;        //中间变量,x
			double dy;        //中间变量y值
			cout << "请输入x，y值，中间用空格隔开" << endl;
			cin >> dx;
			cin >> dy;
			x.push_back(make_pair(dx, dy));
		}
		else if (u == "N")
		{
			break;
		}
		else
		{
			cout << "请输入正确的选择" << endl;
		}
	} while (1);
}
 
vector<double> l_x;      //记录拉格朗系数
double y=0;                //记录最后所求的x对应的值
void L_end(double t, vector<pair<double, double> > x)          //t为需要计算的坐标,x为输入进去的已知离散坐标
{
	int i = 0;
	for (vector<pair<double, double> >::iterator it = x.begin(); it < x.end(); it++)
	{
		l_x.push_back(1);          //拉格朗系数初始化
		int i1 = 0;
		for (vector<pair<double, double> >::iterator it1 = x.begin() ; it1 < x.end();  it1++)
		{
			if (i1 != i)
			{
				double i_first = x[i].first;
				double i1_first = x[i1].first;
 
				l_x[i] = l_x[i] * ((t - i1_first) / (i_first - i1_first));
			}
			i1++;
		}
		i++;
	}
	int i2 = 0;
	for (vector<double>::iterator it2 = l_x.begin() ; it2 < l_x.end();  it2++)
	{
		double l_x_ = l_x[i2];
		double i2_second = x[i2].second;
		y = y+l_x_ * i2_second;  
		i2++;
	}
 
	
}
 
int main()
{
	vector<pair<double, double> > x;
	enter(x);
	cout << "请输入需要计算的x坐标" << endl;
	double temp;
	cin >> temp;
	L_end(temp,x);
	cout << temp << "对应的坐标是：";
	printf("%.5f", y);
}