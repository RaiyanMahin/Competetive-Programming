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
ll dp[11][83][83][2],L;
char st[12];
ll rec(ll p,ll n,ll m,ll fl,ll k)
{
    if(p>=L)
       {
           if(n==0&&m==0)
            return 1;
           else
            return 0;
       }
   ll &ret=dp[p][n][m][fl];
   if(ret!=-1)
        return ret;
   ret=0;
   int d;
   if(fl)
    d=9;
   else
    d=st[p]-'0';
   for(int i=0;i<=d;i++)
   {
       ret=ret+rec(p+1,(n*10+i)%k,(m+i)%k,fl||i<d,k);
   }
   return ret;
}
int main()
{
    ll i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    sn("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld %lld",&a,&b,&k);
        pf("Case %lld: ",cs++);
        if(k==1)
            pf("%lld\n",b-a+1);
        else if(k>82)
        {
            pf("0\n");
        }
        else
         {
              sprintf(st,"%lld",a-1);
                L=strlen(st);
                memset(dp,-1,sizeof(dp));
                a=rec(0,0,0,0,k);
                memset(dp,-1,sizeof(dp));
                sprintf(st,"%lld",b);
                L=strlen(st);
                b=rec(0,0,0,0,k);
                pf("%lld\n",b-a);
         }
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/
