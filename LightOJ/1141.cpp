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
#define N 100000000
#define sn scanf
#define pf printf
#define pb push_back
typedef long long int ll;
using namespace std;
queue<int>Q;
int dis[1005],K,vis[1005],pr[1000];
void seive()
{
    int i,j,l,n=1000;
    memset(vis,0,sizeof(vis));
    for(i=3;i<=sqrt(n);i+=2)
    {
        if(vis[i]==0)
        {
            for(j=i*i;j<=n;j+=2*i)
                if(j%i==0)
                vis[j]=1;
        }
    }
    pr[0]=2;K=1;
    for(i=3;i<=n;i+=2)
        if(vis[i]==0)
        pr[K++]=i;
}
int main()
{
    int i,j,k,l,t,r,s,m,n,a,b,c,d,e,f,g,h,u,v;
    seive();
   // freopen("Input.txt","r",stdin);
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d %d",&n,&m);
         for(i=1;i<=m;i++)
         {
             dis[i]=N;
         }
         Q.push(n);dis[n]=0;
         while(!Q.empty())
         {
             u=Q.front();Q.pop();
             for(i=0;i<K;i++)
             {
                 if(pr[i]>=u)break;
                 if(u%pr[i]==0&&u+pr[i]<=m)
                 {
                     v=u+pr[i];
                     if(dis[v]>dis[u]+1)
                     {
                         dis[v]=dis[u]+1;
                         Q.push(v);
                     }
                 }
             }
         }
         if(dis[m]==N)dis[m]=-1;
        printf("Case %d: %d\n",r,dis[m]);

    }
    return 0;
}


