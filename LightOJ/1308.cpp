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
#define pb push_back
typedef long long int ll;
using namespace std;
vector<int>ar[100005];
vector<int>arr;
vector<int>point;
unsigned long long cnt,ans,gru,ann,vv;

int vis[sz],viss[sz],low[sz],tim[sz],par[sz];
int tm=0,root,subtree=0;
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
void dfs1(int u)
{
    if(viss[u]!=0)
       ann=-1;
    if(ann==-1)
        return ;
    arr.pb(u);
    vis[u]=cnt;
    int i,j=ar[u].size(),v;
    for(i=0;i<j;i++)
    {
        v=ar[u][i];
        if(v!=vv&&vis[v]!=cnt&&(vv!=-1||(vv==-1&&viss[v]==0)))
        {
            dfs1(v);
        }
        else if(viss[v]!=0)
            vv=v;
    }
}
int main()
{
    int i,j,k,l,t,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    scanf("%d",&t);
     while(t--)
     {
         scanf("%d %d",&n,&m);
         memset(vis,0,sizeof(vis));
         memset(viss,0,sizeof(viss));
         root=0;
         for(i=0;i<m;i++)
         {
             scanf("%d %d",&a,&b);
             root=a;
             ar[a].push_back(b);
             ar[b].push_back(a);
         }
         tm=subtree=0;
         c=dfs(root,root);
         memset(vis,0,sizeof(vis));
         memset(low,0,sizeof(low));
         ans=1,gru=0;ann=1;cnt=1;
        for(i=0;i<n;i++)
        {
            if(low[i]==0&&viss[i]==0)
            {
                ann=1;vv=-1;
                dfs1(i);
                if(ann==1)
                {
                    ann=arr.size();
                    gru++;ans=ans*ann;
                    for(k=0;k<ann;k++)
                    {
                        low[arr[k]]=1;
                    }
                }
                arr.clear();
                cnt++;
            }
        }
            printf("Case %d: ",r);
            if(point.size()==0)
                printf("%lld %lld",(ll)2,(ll)((n-1)*n)/2);
            else
                printf("%llu %llu",gru,ans);
         printf("\n");
         point.clear();
         for(i=0;i<n;i++)
            ar[i].clear();
          r++;
     }
    return 0;
}


