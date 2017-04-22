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
ll dp[17][1<<16],vis[17],cnt[17][17];
ll rec(int p,int msk,int n)
{
    if(p>=n)
        return 0;
    ll &ret=dp[p][msk];
    if(ret!=-1)
        return ret;
    ret=100000000000000LL;
    for(int i=0;i<n;i++)
    {
        if((msk&(1<<i))==0)
        {
            ll u=0;
            for(int j=0;j<n;j++)
            {

                if((msk&(1<<j))==0)
                {
                    u+=cnt[i][j];
                }
            }
            ret=min(ret,u+rec(p+1,msk|(1<<i),n));
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
        memset(vis,0,sizeof(vis));
        memset(cnt,0,sizeof(cnt));
        for(i=0;i<n;i++)
        {
            sn("%d",&u);
            u--;
            vis[u]++;
            for(j=0;j<m;j++)
            {
                if(u!=j)
                    cnt[u][j]+=vis[j];
            }
        }
        memset(dp,-1,sizeof(dp));
        pf("Case %d: %d\n",cs++,rec(0,0,m));
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

