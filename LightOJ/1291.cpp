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
#define sz 20005
typedef long long int ll;
using namespace std;
struct T{
int a,b;
}temp;
vector<int>ar[20000];
vector<T>point;
vector<int>node;
map<int,map<int,int> >mv;
//bool mv[10005][10005];
int vis[sz],viss[sz],low[sz],tim[sz],par[sz],cl[sz];
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
               low[u]=Min(low[u],dfs(v,u));
               if(low[v]>tim[u])
               {
                    temp.a=u,temp.b=v;
                   point.push_back(temp);
                   node.push_back(u);
                   node.push_back(v);
                  // pf("%d %d\n",u,v);
               }
           }
           else if(v!=par[u])
                low[u]=Min(low[u],tim[v]);

    }
   return low[u];
}

void dfs1(int u,int c)
{
    cl[u]=c;
    int i,j=ar[u].size(),v;
    for(i=0;i<j;i++)
    {
        v=ar[u][i];
        if(cl[v]!=c&&mv[u][v]==0)
            dfs1(v,c);
    }
}

int main()
{
    int i,j,k,l,t,r,s,m,n,a,b,c,d,e,f,g,h,u,v;
   // freopen("Output.txt","w",stdout);
    scanf("%d",&t);
     for(r=1;r<=t;r++)
     {
         scanf("%d %d",&n,&m);
         memset(vis,0,sizeof(vis));
         memset(viss,0,sizeof(viss));
         for(i=0;i<m;i++)
         {
             scanf("%d %d",&u,&v);
                 ar[u].push_back(v);
                 ar[v].push_back(u);

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
         d=point.size();
         for(i=0;i<d;i++)
         {
              a=point[i].a;b=point[i].b;
              mv[a][b]=mv[b][a]=1;
         }
         c=1;h=0;
         memset(cl,0,sizeof(cl));
         memset(vis,0,sizeof(vis));
         b=node.size();
         for(i=0;i<b;i++)
         {
             a=node[i];
             if(vis[a]==1)continue;
             vis[a]=1;
             dfs1(a,c);
              k=0;
             for(j=0;j<b;j++)
             {
                 if(cl[node[j]]==c&&i!=j)
                   {
                       vis[node[j]]=1;
                       k++;
                   }
             }
             if(k==0)h++;
            c++;
         }
         printf("Case %d: %d\n",r,(h/2)+h%2);
         point.clear();
         node.clear();
         for(i=0;i<=n;i++)
            ar[i].clear();
        mv.clear();
     }
    return 0;
}




