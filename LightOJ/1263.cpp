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
int vis[1005],my,nm,cst[1005];
vector<int>ar[1005];

void dfs(int u)
{
    vis[u]=1;++nm;my=my+cst[u];
    int i,j,v;
    for(i=0,j=ar[u].size();i<j;i++)
    {
        v=ar[u][i];
        if(vis[v]==0)
            dfs(v);
    }
}
int main()
{
    int i,j,k,l,t,r,s,m,n,a,b,c,d,e,f,g,h,u,v;
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);cst[i+1]=a;
        }
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&u,&v);
            ar[u].push_back(v);
            ar[v].push_back(u);
        }
        memset(vis,0,sizeof(vis));a=-1;h=0;
        for(i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                nm=0;my=0;
                dfs(i);
                if(my%nm!=0)
                {
                    h=-1;break;
                }
                else
                {
                    if(a!=-1&&a!=my/nm)
                    {
                        h=-1;break;
                    }
                    a=my/nm;
                }
            }
        }
        if(h==0)
            printf("Case %d: Yes\n",r);
        else
            printf("Case %d: No\n",r);
        for(i=1;i<=n;i++)
        {
            ar[i].clear();
        }
    }
    return 0;
}

