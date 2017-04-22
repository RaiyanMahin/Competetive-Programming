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
ll bigmod(ll a,ll b,ll mod)
{
    if(b==0)return 1;
    if(b%2==0)
    {
        ll hh=bigmod(a,b/2,mod);
        return (hh*hh)%mod;
    }
    else
    {
       return (a*bigmod(a,b-1,mod))%mod;
    }
}
ll dp[70][70];
int main()
{
    ll i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
  #ifdef O_judge
   // freopen(".txt","r",stdin);
  #endif

    e=1;
    memset(dp,0,sizeof(dp));
    for(i=1;i<=63;i++)
    {
        a=e<<(i-1);
        b=(e<<i)-1;
        //pf("%lld\n",b);
        c=(b-a+1);
        h=1;
        for(j=i-1;j>=0;j--)
        {
           if(j==0)
           {
               dp[i][j]=dp[i-1][j]+c;
           }
           else
           {
               dp[i][j]=dp[i-1][j];
               u=(c/h);
               v=(u/2)*h;

               if(v%2LL==1LL)
               {
                   v=v+(c%h);
               }
               dp[i][j]+=v;
           }
           h=h*2;
          // pf("%lld ",dp[i][j]);
        }
       // pf("\n");
    }
    ll aa[77],uu,vv;
    sn("%lld",&t);
    while(t--)
    {
        sn("%lld %lld",&uu,&vv);
        uu=uu-1;
        memset(aa,0,sizeof(aa));
        for(i=1;i<=63;i++)
       {
        a=e<<(i-1);
        b=min((e<<i)-1,uu);
        //pf("%lld\n",b);
        c=(b-a+1);
        if(c<=0)
            break;
        h=1;
        for(j=i-1;j>=0;j--)
        {
           if(j==0)
           {
               aa[j]=aa[j]-c;
           }
           else
           {
               u=(c/h);
               v=(u/2)*h;

               if((u)%2LL==1LL)
               {
                   v=v+(c%h);
               }
               aa[j]-=v;
           }
           h=h*2LL;
          // pf("%lld ",aa[j]);
        }
        //pf("\n");
    }
//     for(j=0;j<i-1;j++)
//        pf("%lld ",aa[j]);
//     pf("\n");
     for(i=1;i<=63;i++)
       {
        a=e<<(i-1);
        b=min((e<<i)-1,vv);
       // pf("%lld\n",b);
        c=(b-a+1);
        if(c<=0)
            break;
        h=1;
        for(j=i-1;j>=0;j--)
        {
           if(j==0)
           {
               aa[j]=aa[j]+c;
           }
           else
           {
               u=(c/h);
               v=(u/2)*h;

               if((u)%2LL==1LL)
               {
                   v=v+(c%h);
               }
               aa[j]+=v;
           }
           h=h*2LL;
         //  pf("%lld ",aa[j]);
        }
       // pf("\n");
    }
//         for(j=0;j<i-1;j++)
//           pf("%lld ",aa[j]);
//            pf("\n");
     ll ans=0;
     for(j=0;j<i-1;j++)
     {
         if(aa[j]%2==1)
         ans=ans+(e<<(i-2-j));
     }
      pf("Case %lld: %lld\n",cs++,ans);
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/


