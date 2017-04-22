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
char st[100];
 ll n,b,k,dp[(1<<16)+2][21];

 ll rec(ll mod,ll mask)
 {
     if(mask==(1<<n)-1)
     {
         if(mod==0)return 1;
         else return 0;
     }
     ll &ret=dp[mask][mod];
     if(ret!=-1)
        return ret;
    ret=0;
     for(int i=0;i<n;i++)
     {
         ll u;
         if(st[i]<='9')
            u=st[i]-'0';
         else
            u=st[i]-'A'+10;
         if(mask&(1<<i))continue;
         ret=ret+rec(((b*mod)+u)%k,mask|(1<<i));
     }
     return ret;
 }

int main()
{
    ll i,j,l,t,cs=1,r=1,s,m,a,c,d,e,f,g,h,u,v;
    sn("%lld",&t);
    while(t--)
    {
        sn("%lld %lld %s",&b,&k,&st);
        n=strlen(st);
        memset(dp,-1,sizeof(dp));
        pf("Case %lld: %lld\n",cs++,rec(0,0));
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

