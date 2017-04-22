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

typedef long long int ll;
using namespace std;
struct T{
int a;
};
vector<int>ar[20000];
map<int,map<int,int> >viss;
int vis[10005],low[10005],tim[10005],d;
int art(int u,int p)
{
   vis[u]=1;
   tim[u]=low[u]=++d;
   int i,j=ar[u].size();
   for(i=0;i<j;i++)
   {
       int v=ar[u][i];
       if(vis[u]==0)
       {
           low[u]=min(low[u],art(v,u));
           if(low[v]>tim[u])
           {
               pf("%d %d\n",u,v);
               viss[u][v]=viss[v][u]=1;
           }
       }
       else if(v!=p)
        low[u]=min(low[u],tim[v]);
   }
   return low[u];
}
int cmp;
void dfs(int u,int p,int c)
{
     cmp++;
     vis[u]=c;
    int i,j=ar[u].size(),v;
    for(i=0;i<j;i++)
    {
        v=ar[u][i];
        if(viss[u][v]!=0);
        else if(vis[v]==0)
        {
            dfs(v,u,3-c);
        }
        else if(vis[v]!=3-c)
        {
             d=-1;
        }
    }
}

int main()
{
    int i,j,k,l,t,r,s,m,n,a,b,c,e,f,g,h,u,v;
     scanf("%d",&t);
     for(r=1;r<=t;r++)
     {
         scanf("%d %d",&n,&m);f=-1;
         for(i=0;i<m;i++)
         {
             scanf("%d %d",&a,&b);
             if(f==-1)
             f=a;
             ar[a].push_back(b);
             ar[b].push_back(a);
         }
         d=0;
         viss.clear();
         memset(vis,0,sizeof(vis));
         c=art(f,-1);
         memset(vis,0,sizeof(vis));
         cmp=d=0;s=0;
         for(i=0;i<n;i++)
         {

             if(vis[i]==0)
             {
                 d=0;cmp=0;
                 dfs(i,-1,1);
                 if(d==-1&&cmp>1)
                 {
                     s=s+cmp;
                 }
             }

         }
         printf("Case %d: %d\n",r,s);
         for(i=0;i<n;i++)
         {
             ar[i].clear();
         }
     }
    return 0;
}


