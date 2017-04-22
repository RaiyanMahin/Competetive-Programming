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
vector<ll>ar[100005];
ll vis[100005],ans,num;
ll  dfs(ll u)
{
    vis[u]=1;
    ll aa=0,an=0,p=0;;
    ll i,j=ar[u].size(),v;
    for(i=0;i<j;i++)
    {
        v=ar[u][i];
        if(vis[v]==0)
        {
            num++;
            p=dfs(v);
         if(p>0)
            {
                an=aa*p;
                p=aa+p;
                aa=p;
                ans=ans+an;
            }
        }
    }
    return p+1;
}
int main()
{
    ll i,j,l,t,r,s,m,n,a,b,c,d,e,f,g,h,u,v;
     scanf("%lld",&t);
     for(r=1;r<=t;r++)
     {
         scanf("%lld",&n);
         memset(vis,0,sizeof(vis));
         for(i=1;i<n;i++)
         {
             scanf("%lld %lld",&u,&v);
             ar[u].push_back(v);
             ar[v].push_back(u);
         }
         num=0;ans=0;
        s=dfs(1);
         printf("Case %lld: %lld %lld\n",r,num,ans);
         for(i=1;i<=n;i++)
              ar[i].clear();
     }
    return 0;
}
