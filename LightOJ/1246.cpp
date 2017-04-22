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
ll ar[55][300],arr[55][300],ncr[55][55],mod=1000000007;
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f;
    ll g,h,u,v;
  #ifdef O_judge
    //freopen(".txt","r",stdin);
  #endif
     memset(ar,0,sizeof(ar));
     for(i=1;i<=52;i++)
     {
         ar[i][0]=1;
         for(j=1;j<300;j++)
         {
             ar[i][j]=(ar[i][j-1]*i)%mod;
         }
     }
     memset(ncr,0,sizeof(ncr));
     ncr[0][0]=1;
     for(i=1;i<=52;i++)
     {
         ncr[i][0]=ncr[i][i]=1;
         for(j=1;j<=52;j++)
         {
             if(j<i)
             {
                 ncr[i][j]=(ncr[i-1][j]+ncr[i-1][j-1])%mod;
             }
         }
     }
     for(i=1;i<=205;i++)
     {
         for(j=1;j<=52&&j<=i;j++)
         {
             u=0;
             for(k=1;k<j;k++)
             {
                 a=ncr[j][k];
                 u=(u+(a*arr[k][i])%mod)%mod;
             }
             arr[j][i]=(ar[j][i]-u+mod)%mod;
         }
     }
     sn("%d",&t);
     while(t--)
     {
         sn("%d %d %d",&n,&m,&k);
         n++;m++;
         a=n*m;
         b=a/2;
         a=a-b;
         ll ans=0;
         for(i=1;i<k;i++)
         {
             u=ncr[k][i];
             v=(arr[i][a]*ar[k-i][b])%mod;
             ans=(ans+(u*v)%mod)%mod;
         }
         if(n==m&&n==1)
            ans=k;
         pf("Case %d: %lld\n",cs++,ans);
     }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

