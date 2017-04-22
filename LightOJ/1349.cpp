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

ll Y[50005],X[50005],Yc[3][50005],Xc[3][50005];

int main()
{
    ll i,j,k,l,t,cs=1,r=1,q,s,m,n,a,b,c,d,e,f,g,h,u,v;
  #ifdef O_judge
     freopen("Output.txt","r",stdin);
  #endif
  sn("%lld",&t);
  while(t--)
  {
      sn("%lld %lld %lld",&n,&m,&q);
      memset(Y,0,sizeof(Y));
      memset(X,0,sizeof(X));
      for(i=0;i<q;i++)
      {
          sn("%lld %lld %lld",&a,&b,&c);
          X[a]+=c;
          Y[b]+=c;
          g=a;h=b;
      }
       memset(Yc,0,sizeof(Yc));
      memset(Xc,0,sizeof(Xc));
      a=0;
      for(i=1;i<=n;i++)
      {
         a=a+X[i];
         Xc[0][i+1]=a+Xc[0][i];
       //  pf("%lld ",Xc[0][i]);
      }
      a=0;// pf("\n",Xc[0][i]);
      for(i=n;i>=1;i--)
      {
           a=a+X[i];
         Xc[1][i-1]=a+Xc[1][i];
         // pf("%lld ",Xc[1][i]);
      }
     // pf("\n");
     a=0;
       for(i=1;i<=m;i++)
      {
           a=a+Y[i];
         Yc[0][i+1]=a+Yc[0][i];
         //pf("%lld ",Yc[0][i]);
      }
    //  pf("\n");
      a=0;
      for(i=m;i>=1;i--)
      {
           a=a+Y[i];
         Yc[1][i-1]=a+Yc[1][i];
         //pf("%lld ",Yc[1][i]);
      }
    //  pf("\n");
      ll ans=1000000000,anx=ans*ans;
      ans=anx;
      for(i=1;i<=n;i++)
      {
          a=Xc[0][i]+Xc[1][i];
          if(a<ans)
          {
              ans=a;
              g=i;
          }
      }
      for(i=1;i<=m;i++)
      {
          a=Yc[0][i]+Yc[1][i];
          if(a<anx)
          {
              anx=a;
              h=i;
          }
      }
      pf("Case %lld: %lld %lld\n",cs++,g,h);
     // pf("Case %lld: %lld %lld\n",cs,ans,anx);
  }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

