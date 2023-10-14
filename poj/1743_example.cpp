#pragma GCC optimize(2)
//#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
#define pi acos(-1.0)
#define e exp(1.0)
#define pb push_back
#define mk make_pair
#define fir first
#define sec second
//#define scf scanf
//#define prf printf
typedef pair<ll,ll> pa;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll maxn=2e5+7;
ll height[maxn],sa[maxn],rk[maxn],tmp[maxn],r[maxn],K,N;
bool cmp(ll i,ll j){//i,j是后缀开始的位置 
	if(rk[i]!=rk[j])
	return rk[i]<rk[j];
	ll r1=i+K<=N?rk[i+K]:-1;//i+K==N 相当于空串 
	ll r2=j+K<=N?rk[j+K]:-1;
	return r1<r2;
}
//倍增法求后缀数组 
void do_sa(){
	ll i,j;
	//给rk[]和sa[]数组赋值, 
	for(i=0;i<=N;i++){
		sa[i]=i;
//		rk[i]=(i==N?-1:r[i]);//包含空串 
		rk[i]=r[i];
	}
	//倍增法求后缀树组 
	for(K=1;K<=N;K<<=1){
		sort(sa,sa+1+N,cmp);
		tmp[sa[0]]=0;//最小一定是空串 
		for(i=1;i<=N;i++)
		tmp[sa[i]]=tmp[sa[i-1]]+(cmp(sa[i-1],sa[i])?1:0);
		//sa[i]和sa[i-1]的顺序千万别弄反了,和上面的cmp函数的定义是对应的,如果写反,当r1==r2是不等价的 
		for(i=0;i<=N;i++)
		rk[i]=tmp[i];
	}
	return ;
}
//height[i]数组存储从i处开始的后缀字符串和排名小于当相邻的位置j处开始的后缀
//字符串子串的最长公共子串长度 
void get_height(){
	ll i,j,k=0;
	for(i=0;i<N;i++){//
		if(k)
		k--;
		else
		k=0;
		j=sa[rk[i]-1];
		while(r[i+k]==r[j+k])
		k++;
		height[rk[i]]=k;
	}
	return ;
}
bool check(ll mid){
	ll i,j;
	ll maxx=-INF,minn=INF;
	for(i=1;i<=N;i++){
		if(height[i]>=mid){
			minn=min(minn,min(sa[i],sa[i-1]));
            maxx=max(maxx,max(sa[i],sa[i-1]));
            if(maxx-minn>mid) return true;
		}
		else{
			maxx=-INF;
			minn=INF;
		}
	}
	return false;
}
int main()
{
//  freopen(".../.txt","w",stdout);
//  freopen(".../.txt","r",stdin);
//	ios::sync_with_stdio(false);
	while(scanf("%lld",&N)&&N){
		ll i,j,k;
//		memset(height,0,sizeof(height));
//		memset(rk,0,sizeof(rk));
//		memset(tmp,0,sizeof(tmp));		
//		memset(sa,0,sizeof(sa));
//		memset(r,0,sizeof(r));
		//求差值串,r[]相当于字符串 
		for(i=0;i<N;i++){
			scanf("%lld",&r[i]);
			if(i)
			r[i-1]=r[i]-r[i-1]+88;
		}
		N--;
		r[N]=0;
		do_sa();
		get_height();
		ll L=0,R=N/2,mid,res=0;
		while(L<=R){
			mid=(R-L)/2+L;
			if(check(mid)){
				L=mid+1;
				res=max(res,mid); 
			}
			else{
				R=mid-1;
			}
		}
		if(res<4){
			printf("0\n");
			continue;
		}
		printf("%lld\n",res+1);	
	}
	return 0;
}

