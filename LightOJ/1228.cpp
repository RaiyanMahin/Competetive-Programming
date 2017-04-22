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

typedef long long int ll;
using namespace std;
struct T{
int a;
};
ll dp[13][13][4100],vis[13][13];

ll rec(int u,int k,int msk,int n)
{
    if(k<0)
        return 0;
    if(msk==(1<<n)-1)
    {
        return 1;
    }
    ll &ret=dp[u][k][msk];
    if(ret!=-1)
        return ret;
    ret=0;

    for(int i=0;i<n;i++)
    {
        if(msk&(1<<i))continue;
        if(vis[i][u])
            ret=ret+rec(i,k-1,msk|(1<<i),n);
        else
            ret=ret+rec(i,k,msk|(1<<i),n);
    }
    return ret;
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v,q;
  #ifdef O_judge
    //freopen(".txt","r",stdin);
  #endif
    sn("%d",&t);
    while(t--)
    {
        sn("%d %d %d",&n,&k,&q);
        memset(vis,0,sizeof(vis));
        for(i=0;i<n;i++)
        {
            sn("%d",&u);
            for(j=0;j<u;j++)
            {
                sn("%d",&a);
                vis[a-1][i]=1;
            }
        }
        for(i=0;i<=n;i++)
        {
            memset(dp,-1,sizeof(dp));
            pf("%lld\n",rec(13,i,0,n));
        }
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

