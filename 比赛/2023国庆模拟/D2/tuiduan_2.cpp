#include <iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
const int MX=1e5+100;
int n,m,par[MX],rk[MX],label[MX];
vector<int> g[MX];
void init(int n)
{
    for(int i=0;i<=n;i++) par[i]=i,rk[i]=0,g[i].clear();
    memset(label,0,sizeof(label));
}
int f(int x)
{
    if(par[x]==x) return x;
    return par[x]=f(par[x]);
}
void unite(int x,int y)
{
    x=f(x);
    y=f(y);
    if(x==y) return ;
    if(rk[x]<rk[y]) par[x]=y;
    else
    {
        par[y]=x;
        if(rk[x]==rk[y]) rk[x]++;
    }
}
bool dfs(int u,int num)
{
 
    if(num==1&&f(u)==f(n) ) return true;
    if(num==n&&f(u)==f(1) ) return true;
    if(label[u]!=0&&label[u]!=num) return false;
    label[u]=num;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(label[v]!=num) if(dfs(v,num)) return true;
    }
    g[u].clear();
    return false;
}
int main()
{
    while(cin>>n>>m)
    {
        init(n);
        label[1]=1;label[n]=n;
        int ans=-1;
        for(int i=0;i<m;i++)
        {
            int x,y;
            char c;
            scanf("\nA%d %c A%d",&x,&c,&y);
            if(ans>0) continue;
            if(c=='=')
            {
                unite(x,y);
                g[x].push_back(y);
                if(label[x]==1 ||label[x]==n)
                    if(dfs(x,label[x])) ans=i+1;
 
 
                g[y].push_back(x);
                if(label[y]==1||label[y]==n)
                    if(dfs(y,label[y])) ans=i+1;
            }
            else
            {
                g[x].push_back(y);
                if( label[x] == 1 || label[x]==n)
                    if(dfs(x,label[x])) ans=i+1;
            }
 
        }
        cout<<ans<<endl;
    }
    return 0;
}