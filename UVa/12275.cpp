
//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<set>
#include <iostream>
#include<stack>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf
#define pb push_back
#define mp make_pair

typedef long long int ll;
using namespace std;
struct T{
int a,b,c;
};

bool cmp( T x,T y)
{
    return x.c<y.c;
}
int par[400],beg[400],vis[400],cnt;
vector<T>ar[40000];
vector<int>Ed[400];
void dfs(int u)
{
    vis[u]=1;cnt++;
    int i,j=Ed[u].size(),v;
    for(i=beg[u];i<j;i++)
    {
        v=Ed[u][i];
        if(vis[v]==0)
        {
            dfs(v);
        }
    }
}
int parent(int u)
{
    if(par[u]==u)
    {
        return u;
    }
    else return par[u]=parent(par[u]);
}

int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    while(sn("%d",&n)!=EOF&&n)
    {
        sn("%d",&m);
        h=0;
        for(i=0;i<m;i++)
        {
            sn("%d %d %d",&a,&b,&c);
            T tem;h=max(h,c);
            tem.a=a;tem.b=b;
            ar[c].pb(tem);
        }
        int ans=1000000;
        s=0;a=1;
        memset(beg,0,sizeof(beg));
        for(i=0;i<=n;i++)par[i]=i;
        int se=0,des=0;
        for(i=1;i<=h;i++)
        {
            for(j=0;j<ar[i].size();j++)
            {
                Ed[ar[i][j].a].pb(ar[i][j].b);
                Ed[ar[i][j].b].pb(ar[i][j].a);
                u=parent(ar[i][j].a);
                v=parent(ar[i][j].b);
                if(u!=v)
                {
                    par[max(u,v)]=min(u,v);
                    s++;
                }
            }
            if(s==n-1)
            {
                cnt=0;
                memset(vis,0,sizeof(vis));
                dfs(0);
                while(cnt==n&&a<=i)
                {
                    ans=min(i-a,ans);
                    for(j=0;j<ar[a].size();j++)
                    {
                        beg[ar[a][j].a]++;
                        beg[ar[a][j].b]++;
                    }
                    a++;
                    cnt=0;
                    memset(vis,0,sizeof(vis));
                    dfs(0);
                }
            }
        }
        pf("%d\n",ans);
        for(i=0;i<=h;i++)
        {
            ar[i].clear();
        }
        for(i=0;i<=n;i++)
        {
            Ed[i].clear();
        }
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/
