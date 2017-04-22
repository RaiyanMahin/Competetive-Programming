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
struct T{
int a,b;
}temp;
vector<int>ar[100005];
vector<T>point;
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
               low[u]=min(low[u],dfs(v,u));
               if(low[v]>tim[u])
               {
                   if(u>v)
                   temp.a=v,temp.b=u;
                   else
                    temp.a=u,temp.b=v;
                   point.push_back(temp);
               }
           }
           else if(v!=par[u])
                low[u]=min(low[u],tim[v]);

    }
   return low[u];
}

bool cmp(T x,T y)
{
    if(x.a==y.a)
        return x.b<y.b;
    return x.a<y.a;
}

int main()
{
    int i,j,k,l,t,r,s,m,n,a,b,c,d,e,f,g,h,u,v;
    char st[10000],*cp;
    scanf("%d",&t);
     for(r=1;r<=t;r++)
     {
         scanf("%d",&n);
         memset(vis,0,sizeof(vis));
         memset(viss,0,sizeof(viss));
         for(i=0;i<n;i++)
         {
             scanf("%d (%d)",&u,&m);
             for(j=0;j<m;j++)
             {
                 scanf("%d",&v);
                 ar[u].push_back(v);
                 ar[v].push_back(u);
             }
         }
         tm=0;
         for(i=0;i<n;i++)
         {
             if(vis[i]==0)
           {
               tm=subtree=0;root=1;
                 dfs(i,i);
           }
         }
         printf("Case %d:\n",r);
         printf("%d critical links\n",d=point.size());
         sort(point.begin(),point.end(),cmp);
        for(i=0;i<d;i++)
        {
            printf("%d - %d\n",point[i].a,point[i].b);
        }
         point.clear();
         for(i=0;i<=n;i++)
            ar[i].clear();

     }
    return 0;
}



