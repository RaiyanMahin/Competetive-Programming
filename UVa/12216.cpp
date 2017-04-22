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
ll vis[10008]={0},pr[10000],mod=100000007;
int main()
{
    ll i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    for(i=3;i<=sqrt(10008);i+=2)
    {
        if(vis[i]==0)
        {
            for(j=i*i;j<=10008;j+=2*i)
            {
                if(j%i==0)
                    vis[j]=1;
            }
        }
    }
    pr[0]=2;c=1;
    for(i=3;i<=10008;i+=2)
    {
        if(vis[i]==0)
            pr[c++]=i;
    }

    while(sn("%lld %lld %lld",&n,&m,&t)==3&&t&&n&&m)
    {
        vector<ll >ar;
        for(i=0;i<c;i++)
        {
           if(pr[i]*pr[i]>n)
                break;
            u=0;
           while(n%pr[i]==0)
           {
               n/=pr[i];
               u++;
           }
           if(u>0)
           {
               ar.pb(u*m);
           }
        }
        if(n>1)
           {
               ar.pb(1*m);
           }
        ll dp[10000],dpp[10000];
        l=ar.size();
        dp[l]=1;
        for(i=l-1;i>=0;i--)
        {
            a=ar[i]/t;
            dp[i]=((a+1)%mod * dp[i+1])%mod;
        }
        ll ans=0;
        dpp[0]=1;
        for(i=0;i<l;i++)
        {
            a=ar[i]/t;
            b=ar[i]/(t+1);
            a=a-b;
            d=((a%mod)*(dp[i+1]))%mod;
            d=(d*dpp[i])%mod;
            ans=(ans+d)%mod;
            dpp[i+1]=(dpp[i]*((b+1)%mod))%mod;

        }
        pf("Case %lld: %lld\n",cs++,ans);
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

