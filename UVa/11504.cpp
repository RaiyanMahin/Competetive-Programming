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

vector<int>ar[100005];
vector<int>arr[100005];
vector<int>order;
int vis[100005],viss[100005];
void dfs1(int u,int n)
{
    vis[u]=1;
    for(int i=0;i<ar[u].size();i++)
    {
        int v=ar[u][i];
        if(vis[v]==0)
        {
            dfs1(v,n);
        }
    }
    order.push_back(u);
}

void dfs2(int u,int c)
{
      vis[u]=c;
    for(int i=0;i<arr[u].size();i++)
    {
        int v=arr[u][i];
        if(vis[v]==0)
        {
            dfs2(v,c);
        }
    }
}

int main()
{
    int i,j,k,l,t,r,s,m,n,a,b,c,d,e,f,g,h,u,v;
   scanf("%d",&t);
   while(t--)
   {
       scanf("%d %d", &n,&m);
       for(i=0;i<m;i++)
       {
           scanf("%d %d",&a,&b);
           ar[a].push_back(b);
           arr[b].push_back(a);
       }
       memset(vis,0,sizeof(vis));
       for(i=1;i<=n;i++)
       {
           if(vis[i]==0)
           {
               dfs1(i,n);
           }
       }
       c=0;
       memset(vis,0,sizeof(vis));
       for(i=order.size()-1;i>=0;i--)
       {
           if(vis[order[i]]==0)
           {
               dfs2(order[i],c+1);c++;
           }
       }
       memset(viss,0,sizeof(viss));
       for(i=1;i<=n;i++)
       {
           for(j=0;j<ar[i].size();j++)
           {
               v=ar[i][j];
               if(vis[i]!=vis[v])
               {
                   viss[vis[v]]++;
               }
           }
       }
       int cnt=0;
       for(i=1;i<=c;i++)
        if(viss[i]==0)
        cnt++;
       printf("%d\n",cnt);
       for(i=1;i<=n;i++)
       {
           arr[i].clear();
           ar[i].clear();
       }
       order.clear();
   }
    return 0;
}



