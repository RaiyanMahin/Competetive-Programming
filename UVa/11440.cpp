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
bool vis[10000004];
vector<ll>pr;
void prim()
{
    ll i,j,n=10000001,m=sqrt(n);
    memset(vis,0,sizeof(vis));
    for(i=2;i<=m;i++)
    {
        if(vis[i]==0)
        {
            for(j=i*i;j<=n;j+=i*2)
                vis[j]=1;
        }
    }
    pr.pb(2ll);
    for(i=3;i<=n;i+=2)
        if(vis[i]==0)
         pr.pb(i);
}
ll fact[10000004],p1[10000004],p2[10000004];
int main()
{
    ll i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v,mod=100000007;
  #ifdef O_judge
    //freopen(".txt","r",stdin);
  #endif
    prim();
    fact[1]=1;
    for(i=2;i<=10000001;i++)
    {
        fact[i]=(i*fact[i-1])%mod;
    }
    l=pr.size();
    p1[0]=p2[0]=1;
    for(i=0;i<l;i++)
    {
        p1[i+1]=(pr[i]*p1[i])%mod;
        p2[i+1]=((pr[i]-1)*p2[i])%mod;
    }
    while(sn("%lld %lld",&n,&m)==2)
    {
        if(n==0&&m==0)break;
        a=fact[n];
        l=0;h=pr.size()-1;
        ll mid;
        while(l<=h)
        {
            mid=(l+h)/2;
            if(pr[mid]<=m)
            {
                if(mid<pr.size()-1&&pr[mid+1]<=m)
                {
                    l=mid+1;
                }
                else
                 break;
            }
            else
                h=mid-1;
        }
       // pf("%lld\n",mid);
        if(m<2)
         mid=-1;
        u=p1[mid+1];v=p2[mid+1];
        v=(u-v+mod)%mod;
        v=(v*a)%mod;
        u=bigmod(u,mod-2,mod);
        pf("%lld\n",(a-(v*u)%mod+mod-1+mod)%mod);
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

