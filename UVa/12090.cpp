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
ll vis[5000000]={0};
vector<ll>pr,str;
vector<pair<ll,ll> >dv;
void seive()
{
    ll i,j,k,m=4000000,n;
    for(i=3;i<sqrt(m);i+=2)
    {
        if(vis[i]==0)
        {
            for(j=i*i;j<=m;j+=i*2)
            {
                if(j%i==0)vis[j]=1;
            }
        }
    }
    pr.pb(2);
    for(i=3;i<m;i+=2)
        if(vis[i]==0)
    {
        pr.pb(i);
    }
}
void Generate(ll cur,ll num,ll sz)
{
    ll i,val,u;

    if(cur==sz)
    {
        str.pb(num);
    }
    else
    {
        val=1;u=dv[cur].second;
        for(i=0;i<=u;i++)
        {
            Generate(cur+1,num*val,sz);
            val=val*dv[cur].first;
        }
    }
}

int main()
{
    ll i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v,dp[50];
    seive();
    k=pr.size();
    while(sn("%lld",&n)==1&&n)
    {
        b=n;str.clear();dv.clear();k=pr.size();
        for(i=0;i<k;i++)
        {
            if(pr[i]*pr[i]>n)break;
            c=0;
            while(n%pr[i]==0)
            {
                n/=pr[i];c++;
            }
            if(c>0)
            {
               // pf("%lld %lld\n",pr[i],c);
                dv.pb(make_pair(pr[i],c));
            }
        }
        if(n>1)
            {
               //  pf("%lld %lld\n",n,1);
                dv.pb(make_pair(n,1));
            }
        Generate(0,1,dv.size());
        ll ans=0;
        k=str.size();n=b;
        for(i=0;i<k;i++)
        {
            if(str[i]<=1)continue;
            c=0;n=b;
            while(n%str[i]==0)
            {
                n/=str[i];c++;
            }
            ans=ans+c;
        }
        n=b;
        pf("%lld %lld\n",n,ans);
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

