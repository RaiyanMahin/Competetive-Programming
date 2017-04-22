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
vector<int>ar[200];
int vis[200],p;
void dfs(int u,int c)
{
    vis[u]=c;
    int i,j,v;
    for(i=0,j=ar[u].size();i<j;i++)
    {
        v=ar[u][i];
        if(vis[v]!=1-vis[u]&&vis[v]!=1)
            dfs(v,1-vis[u]);
    }
}
void dfss(int d)
{

    int j,k,u;
    for(j=0,k=ar[d].size();j<k;j++)
    {
        u=ar[d][j];
       if(vis[u]==-1)
       {
           vis[u]=(vis[d]+1)%2;
           dfss(u);
       }
       else if(vis[u]==vis[d])
         p=2;
    }
}

int main()
{
    int i,j,k,l,t,r,s,m,n,a,b,c,d,e,f,g,h,u,v;
      scanf("%d",&t);
      for(r=1;r<=t;r++)
      {
          scanf("%d %d",&n,&m);a=0;
          memset(vis,-1,sizeof(vis));
          for(i=0;i<m;i++)
          {
              scanf("%d %d",&u,&v);
              ar[u].push_back(v);
              ar[v].push_back(u);
              if(u==1||v==1)a=1;
          }
          p=1;dfss(1);
          if(p==1)
          {
               memset(vis,-1,sizeof(vis));
              dfs(1,1);
              s=0;
              for(i=1;i<=n;i++)
              {
                  if(vis[i]==1)s++;
                  ar[i].clear();
              }
          }
          else
          {
              s=0;
              for(i=1;i<=n;i++)
              {
                  if(vis[i]!=-1)s++;
                  ar[i].clear();
              }
          }
          if(a==0)
            s=0;
          printf("Case %d: %d\n",r,s);
      }
    return 0;
}

