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
#define mp make_pair

typedef long long int ll;
using namespace std;
struct T{
ll vv,nd;
bool operator <(const T & b)const
	{
		return (b.vv<vv);
	}
}tmp;
vector<ll>E[105],cst[105];
ll cost[105],dis[101][101];
priority_queue< T >Q;
long long Inf=1223372036854775805;
int main()
{
    ll i,j,k,l,t,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v,q,x,y;
     scanf("%lld",&t);
     while(t--)
     {
         scanf("%lld %lld",&n,&m);

         for(i=0;i<n;i++)
         {
             scanf("%lld",&cost[i]);
         }
         for(i=0;i<m;i++)
         {
             scanf("%lld %lld %lld",&u,&v,&c);
             E[u].pb(v);
             E[v].pb(u);
             cst[u].pb(c);
             cst[v].pb(c);
         }
         scanf("%lld",&q);
         printf("Case %lld:\n",r++);
         while(q--)
         {
             scanf("%lld %lld %lld",&c,&s,&a);
             for(i=0;i<=n;i++)
              {
                  for(j=0;j<=c;j++)
                  {
                      dis[i][j]=Inf;
                  }
              }
             for(j=0;j<=c;j++)
             {
                 dis[s][i]=j*cost[s];
             }
             tmp.vv=0;tmp.nd=s;
             Q.push(tmp);
             while(!Q.empty())
             {
                 tmp=Q.top();Q.pop();
                 u=tmp.nd;
                 for(i=0,j=E[u].size();i<j;i++)
                 {
                     bool ps=false;
                     v=E[u][i];
                     d=cst[u][i];
                     if(d<=c)
                     {
                         for(k=0;k<=c;k++)
                         {
                             if(d+k<=c&&dis[v][k]>dis[u][d+k])
                             {
                                dis[v][k]=dis[u][d+k];
                                ps=true;
                             }
                          if(k>0&&dis[v][k]>dis[v][k-1]+cost[v])
                             {
                                 dis[v][k]=dis[v][k-1]+cost[v];
                                 ps=true;
                             }
                         }
                     }
                     if(ps)
                     {
                         tmp.nd=v;
                         tmp.vv=dis[v][0];
                         Q.push(tmp);
                     }
                 }
             }
             if(dis[a][0]>=Inf)
                printf("impossible\n");
             else
               printf("%lld\n",dis[a][0]);
         }
         for(i=0;i<=n;i++)
            E[i].clear(),cst[i].clear();
     }
    return 0;
}
