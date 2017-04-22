//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<set>
#include <iostream>
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

const double PI=2.0*acos(0);

typedef long long int ll;
using namespace std;
int dis[20][20],dp[(1<<15)],H,deg[22];
vector<int>nd;
int rec(int msk,int n)
{
    if(msk==(1<<n)-1)
        return 0;
    int &ret=dp[msk];
    ret=1000000000;
    for(int i=0;i<nd.size();i++)
    {
        if((msk&(1<<i))==0)
        for(int j=i+1;j<nd.size();j++)
        {
            int u=(1<<i)|(1<<j);
            if((msk&u)==0)
            {
                ret=min(ret,dis[nd[i]][nd[j]]+rec(msk|u,n));
            }
        }
    }
    return ret;
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%d",&t);
    while(t--)
    {
        sn("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                dis[i][j]=1000000000;
            dis[i][i]=0;
        }
        s=0;
        memset(deg,0,sizeof(deg));
        for(i=0;i<m;i++)
        {
            sn("%d %d %d",&u,&v,&c);u--;v--;
            s=s+c;
            deg[u]++;deg[v]++;
            dis[u][v]=dis[v][u]=min(dis[u][v],c);
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                for(k=0;k<n;k++)
                {
                    dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
        for(i=0;i<n;i++)
            if(deg[i]&1)
               nd.pb(i);
        memset(dp,-1,sizeof(dp));
        pf("Case %d: %d\n",cs++,s+rec(0,nd.size()));
        nd.clear();
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

