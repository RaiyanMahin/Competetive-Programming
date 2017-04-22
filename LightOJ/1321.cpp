//BISMILLAHIR RAHMANIR RAHIM
//#include <bits/stdc++.h>
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
#define eps 1e-9
double Inf=1000000000000000.0;

typedef long long int ll;
using namespace std;
struct T{
int nd;
double vv;

bool operator<(const T &b)const
{
     return vv<b.vv;
}
}temp;
double dis[105];
vector<ll>E[105];
vector<double>cst[105];
priority_queue<T>Q;
int vis[105];
int main()
{
    ll i,j,k,l,t,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v,tm;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld %lld %lld",&n,&m,&s,&tm);
        for(i=0;i<m;i++)
        {
            double p;
            scanf("%lld %lld %lf",&u,&v,&p);
            E[u].pb(v);
            E[v].pb(u);
            p=p/100.0;
            cst[u].pb(p);
            cst[v].pb(p);
        }
        for(i=0;i<=n;i++)
            dis[i]=0.0,vis[i]=0;
            dis[0]=1.0;
        temp.nd=0;temp.vv=1.0;
        Q.push(temp);
        while(!Q.empty())
        {
            temp=Q.top();Q.pop();
            u=temp.nd;
            if(vis[u])
                continue;
            for(i=0,j=E[u].size();i<j;i++)
            {
                v=E[u][i];
                double p=cst[u][i]*dis[u];
                if(vis[v]==0&&dis[v]<p)
                {
                    dis[v]=p;
                    temp.nd=v;temp.vv=dis[v];
                    Q.push(temp);
                }
            }
            vis[u]=1;
        }

        dis[n-1]=((double)s*2.0*tm)/dis[n-1];
        printf("Case %lld: %.9lf\n",r++,dis[n-1]);
        for(i=0;i<=n;i++)
            E[i].clear(),cst[i].clear();
    }
    return 0;
}
