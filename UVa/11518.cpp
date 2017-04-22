//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;

vector<int>ar[10000];
int vis[100000];
int p;

void dfs(int u,int n)
{
    vis[u]=1;
    for(int i=0,v,j=ar[u].size();i<j;i++)
    {
        v=ar[u][i];
        if(vis[v]==0)
        {
            dfs(v,n);p++;
        }
    }
}

int main()
{
    int i,j,k,l,t,r,s,m,n,a,b,c,d,e,f,g,h;
     scanf("%d",&t);
     for(r=1;r<=t;r++)
     {
         scanf("%d %d %d",&n,&m,&l);
         for(i=0;i<m;i++)
         {
             scanf("%d %d",&a,&b);
             ar[a].push_back(b);
         }
         memset(vis,0,sizeof(vis));
         c=0;
         for(i=0;i<l;i++)
         {
             scanf("%d",&a);

             if(vis[a]==0&&a<=n)
             {
                  p=1;
                 dfs(a,n);
                 c+=p;
             }
         }
         printf("%d\n",c);
         for(i=1;i<=n;i++)
            ar[i].clear();
     }
    return 0;
}

