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
#define pb push_back
typedef long long int ll;
using namespace std;

vector<int>ar[1005];
int vis[1005],vis1[1005],nd[200];
void dfs(int u)
{
    vis[u]++;
    vis1[u]=1;
    int i,j,v;
    for(i=0,j=ar[u].size();i<j;i++)
    {
        v=ar[u][i];
        if(vis1[v]==0)
            dfs(v);
    }
}

int main()
{
    int i,j,k,l,t,r,s,m,n,a,b,c,d,e,f,g,h,u,v;
   // freopen("Input.txt","r",stdin);
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d %d %d",&k,&n,&m);
        for(i=0;i<k;i++)
        {
            scanf("%d",&nd[i]);
        }
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&u,&v);
            ar[u].pb(v);
        }
        memset(vis,0,sizeof(vis));
        for(i=0;i<k;i++)
        {
             memset(vis1,0,sizeof(vis1));
            dfs(nd[i]);
        }
        s=0;
        for(i=1;i<=n;i++)
            if(vis[i]==k)s++;
        printf("Case %d: %d\n",r,s);
        for(i=1;i<=n;i++)
            ar[i].clear();
    }
    return 0;
}

