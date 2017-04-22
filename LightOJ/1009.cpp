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

vector<int>ar[20005];
vector<int>aa;
int vis[20005],a,b;

void dfs(int u,int c)
{
    vis[u]=1;
    if(c%2==0)
        b++;
    else
        a++;
    int i,j;
    for(i=0,j=ar[u].size();i<j;i++)
    {
        int v=ar[u][i];
        if(vis[v]!=1)
        {
            dfs(v,c+1);
        }
    }
}

int main()
{
    int i,j,k,l,t,r,s,m,n,c,d,e,f,g,h,u,v;
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        memset(vis,-1,sizeof(vis));
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&u,&v);
            if(vis[u]==-1)
                aa.push_back(u);
                 if(vis[v]==-1)
                aa.push_back(v);
            ar[u].push_back(v);
            ar[v].push_back(u);
            vis[u]=vis[v]=0;
        }
        l=aa.size();
        s=0;
        for(i=0;i<l;i++)
        {
            if(vis[aa[i]]==0)
            {
                a=0;b=0;
                dfs(aa[i],1);
                s+=(a>b)?a:b;
            }
        }
        printf("Case %d: %d\n",r,s);
        for(i=0;i<l;i++)
        {
            ar[aa[i]].clear();
        }
        aa.clear();
    }
    return 0;
}

