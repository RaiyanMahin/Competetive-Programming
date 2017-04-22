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
ll dp[(1<<15)+5][16],ar[100005],vis[(1<<15)+5],bit=15;
ll pr[20]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
ll rec(int p,int msk,int st)
{
  //  if(msk==0)
    //    return 0;
    if(p>=bit)
        return vis[msk];
    ll &ret=dp[msk][p];
    if(ret!=-1)
        return ret;
     ret=0;
     ret=rec(p+1,msk,st);
    if((msk&(1<<p)))
     ret=ret+rec(p+1,msk^(1<<p),st);
    return ret;
}
int main()
{
    ll i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%lld",&t);
    while(t--)
    {
        sn("%lld",&n);
        for(i=0;i<n;i++)
        {
           sn("%lld",&ar[i]);
        }
        sort(ar,ar+n);
        s=0;
        memset(vis,0,sizeof(vis));
        for(i=0;i<n;i++)
        {
            c=0;
            for(j=0;j<bit;j++)
            {
                if(ar[i]%pr[j]==0)
                    c|=(1<<j);
            }
            ar[i]=c;
            vis[c]++;
        }
        memset(dp,-1,sizeof(dp));
        m=(1<<bit);
        ll ans=0;
        for(i=0;i<n;i++)
        {
            v=0;
            for(j=0;j<bit;j++)
            {
                if(ar[i]&(1<<j))
                {
                    u=(m-1);
                    u=u^ar[i];
                    ans=ans+rec(0,u|(1<<j),j);
                    u=(m-1)^ar[i];
                    ans-=rec(0,u,j);
                    v=0;
                }
            }
            ans=ans+rec(0,(m-1)^ar[i],15);
        }
        pf("%lld\n",ans);
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/


