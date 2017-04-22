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
ll vis[45002],ck,ar[101];
ll tt;
int main()
{
    ll i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
  #ifdef O_judge
    //freopen("out.txt","w",stdout);
  #endif
    sn("%lld",&t);
    while(t--)
    {
        sn("%lld",&n);tt=0;
        memset(vis,-1,sizeof(vis));
        for(i=0;i<n;i++)
        {
            sn("%lld",&ar[i]);
            tt=tt+ar[i];
            //vis[ar[i]]=1;
        }
       h=(1LL<<52LL);
       vis[0]=0;
       for(i=0;i<n;i++)
       {
           for(j=tt-ar[i];j>=0;j--)
           {
               if(vis[j]!=-1)
               {
                   a=vis[j];
                   if(a==0)
                    a=1;
                   else a=a*2;
                   if(vis[j+ar[i]]==-1)
                   vis[j+ar[i]]=a;
                   vis[j+ar[i]]|=a;
                   if(vis[j+ar[i]]&h)
                    vis[j+ar[i]]^=h;
               }
           }
       }
       ll ans=100000000;
       a=max((n/2)-1,0ll);
       g=1ll<<a;
      // pf("%lld %lld %lld\n",vis[798],g,(n/2));
       for(i=tt;i>=0;i--)
       {
           if(vis[i]!=-1&&(vis[i]&g)&&ans>abs(tt-i-i))
           {

                ans=min(ans,abs(tt-i-i));
                u=min(tt-i,i);
                v=max(tt-i,i);
           }
       }
       ck++;
       pf("%lld %lld\n",u,v);
       if(t)
        pf("\n");
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

