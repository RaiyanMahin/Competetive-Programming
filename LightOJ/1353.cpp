//BISMILLAHIR RAHMANIR RAHIM
#include <bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf
#define pb push_back

typedef long long int ll;
using namespace std;
struct T{
int a;
};
vector<int>ar[100005];
int ans=0,vis[100005];
int up[100005];
int down[100005];
void dfs(int u)
{
    vis[u]=1;
    int i,j=ar[u].size(),v,d;
    for(i=0;i<j;i++)
    {
        d=ar[u][i];
        v=abs(d);
        if(vis[v]==0)
        {
               dfs(v);
              if(d>0&&up[v]==0)
                up[v]++;
             if(d<0&&down[v]==0)
                down[v]++;
           if(d>0)
            {
                 if(up[v]>down[u])
                {
                    up[v]-=down[u];ans+=down[u];
                    down[u]=0;
                }
                else
                {
                     ans+=up[v];
                    down[u]-=up[v];
                    up[v]=0;
                }

                up[u]+=up[v];
                ans+=down[v];
                down[v]=0;
            }
           else
           {
                  if(up[u]>down[v])
                {
                    up[u]-=down[v];ans+=down[v];
                    down[v]=0;
                }
                else
                {
                     ans+=up[u];
                    down[v]-=up[u];
                    up[u]=0;
                }
                down[u]+=down[v];
                ans+=up[v];
                up[v]=0;
           }

        }
    }

}
int main()
{
    int i,j,k,l,t,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<=n;i++)
        {
            vis[i]=0;
            up[i]=0;
            down[i]=0;
        }
        for(i=1;i<n;i++)
        {
            scanf("%d %d",&u,&v);
            u++;v++;
            ar[u].pb(v);
            ar[v].pb(-u);
        }
        ans=0;
        dfs(1);
        ans=ans+up[1]+down[1];
        printf("Case %d: %d\n",r++,ans);
        for(i=0;i<=n;i++)
            ar[i].clear();
    }
    return 0;
}


