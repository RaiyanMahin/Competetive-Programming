//BISMILLAHIR RAHMANIR RAHIM
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
//#define sz 100005
typedef long long int ll;
using namespace std;
vector<int>ar[20000];
vector<int>point;
int vis[20000],viss[20000],low[20000],tim[20000],par[20000];
int tm=0,root,subtree=0;
int dfs(int u,int p)
{
     vis[u]=1;
     par[u]=p;
     tim[u]=low[u]=++tm;
     int i,v,j=ar[u].size(),k;
     for(i=0;i<j;i++)
     {
         v=ar[u][i];
         if(vis[v]==0&&v!=p)
         {
                 if(u==root)subtree++;
             low[u]=min(low[u],dfs(v,u));
             if(low[v]>=tim[u]&&viss[u]==0&&u!=root)
             {
                 viss[u]=1;
                 point.push_back(u);
             }
             else if(u==root&&subtree>1&&viss[u]==0)
             {
                 viss[u]=1;
                 point.push_back(u);
             }
         }
         else if(v!=par[u])
         {
             low[u]=min(low[u],tim[v]);
         }
     }
     return low[u];
}

int main()
{
    int i,j,k,l,t,r,s,m,n,a,b,c,d,e,f,g,h,u,v;
    scanf("%d",&t);
     for(r=1;r<=t;r++)
     {
         scanf("%d %d",&n,&m);
         memset(vis,0,sizeof(vis));
         memset(viss,0,sizeof(viss));
         for(i=0;i<m;i++)
         {
             scanf("%d %d",&a,&b);
             ar[a].push_back(b);
             ar[b].push_back(a);
         }
        memset(tim,0,sizeof(tim));
        memset(low,0,sizeof(low));
        for(i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                 tm=subtree=0;root=i;
                   c=dfs(i,i);
            }
        }

//         for(i=0;i<point.size();i++)
//            printf(" %d",point[i]);
//         printf("\n");
         printf("Case %d: %d\n",r,point.size());
         point.clear();
         for(i=1;i<=n;i++)
            ar[i].clear();

     }
    return 0;
}


