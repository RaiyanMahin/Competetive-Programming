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

ll fib[50];
int vis[55];
vector < vector <int> > arrr;
int main()
{
    ll i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    fib[0]=1;fib[1]=2;
     for(i=2;i<=46;i++)
     {
         fib[i]=fib[i-1]+fib[i-2];
     }
   //  pf("%lld\n",fib[45]);
     sn("%lld",&t);
     while(t--)
     {
         sn("%lld",&n);
         memset(vis,0,sizeof(vis));
         i=45;
         while(n>0&&i>=0)
         {
             if(fib[i]<=n)
             {
                 n=n-fib[i];
                 vis[i]=1;
                 i=i-2;
             }
             else
                i--;
         }
         pf("Case %lld: ",cs++);
         a=0;
         for(i=45;i>=0;i--)
         {
             if(vis[i]==1)
             {
                 pf("1");a=1;
             }
             else if(a==1)
                pf("0");
         }
         pf("\n");
     }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

