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
#define sz 100005
typedef long long int ll;
using namespace std;
vector<int>ar[100005];
vector<int>point;
int vis[sz],viss[sz],low[sz],tim[sz],par[sz];
int tm=0,root,subtree;

int Min(int a,int b)
{
    return a<b?a:b;
}

int dfs(int u,int p)
{
    vis[u]=1;
    par[u]=p;
    tim[u]=low[u]=++tm;
    int i,v;
    for( i=0;i<ar[u].size();i++)
    {
        v=ar[u][i];
        if(!vis[v]&&v!=p)
           {
               if(u==root)
                subtree++;

               low[u]=min(low[u],dfs(v,u));
               if(low[v]>=tim[u]&&viss[u]==0&&u!=root)
               {
                   viss[u]=1;
                   point.push_back(u);
               }

               if(u==root&&subtree>1&&viss[u]==0)
               {
                   viss[u]=1;
                   point.push_back(u);
               }

           }
           else if(v!=par[u])
                low[u]=min(low[u],tim[v]);

    }
   return low[u];
}
int main()
{
    int i,j,k,l,t,r,s,m,n,a,b,c,d,e,f,g,h,u,v;
    char st[10000],*cp;
     while(scanf("%d",&n)==1)
     {
         if(n==0)
            break;
         memset(vis,0,sizeof(vis));
         memset(viss,0,sizeof(viss));
         getchar();
         while(gets(st))
         {
             j=0;
             if(st[0]=='0')break;
             cp=strtok(st," ");
             while(cp!=NULL)
             {
                 if(j==0)
                    a=atoi(cp);
                 else
                 {
                     b=atoi(cp);
                     ar[a].push_back(b);
                     ar[b].push_back(a);
                 }
                 cp=strtok(NULL," ");
                 j++;
             }

         }
       // memset(low,0,sizeof(low));
         tm=0;
         for(i=1;i<=n;i++)
         {
             if(vis[i]==0)
           {
               tm=subtree=0;root=1;
                 dfs(i,i);
           }
         }
         printf("%d\n",point.size());
         point.clear();
         for(i=1;i<=n;i++)
            ar[i].clear();

     }
    return 0;
}


