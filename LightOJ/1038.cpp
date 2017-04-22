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
double dp[100005];
int vis[100005]={0};

double rec(int n)
{
    if(n==1)return 0.0;
    if( vis[n]==0 ) return 2.0;
    if(vis[n]==2)return dp[n];
    vis[n]=2;
    double &ret=dp[n],p;
    ret=0;
    int u=0,h=sqrt(n);
    for(int i=2;i<h+1;i++)
    {
        if(n%i==0)
        {
            int a=n/i;
            if(i!=a)
            {
                ret=ret+1+rec(i)+1+rec(a);u=u+2;
            }
            else
            {
                ret=ret+1+rec(n/i);u++;
            }
        }
    }
    ret+=1;
   p=(double)u+2;
   ret=ret/p + 1.0/p;
   ret=ret/(1.0-(1.0/p));
   return ret;
}

int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
    vis[1]=1;
    for(i=3;i<sqrt(100002)+1;i+=2)
    {
        if(vis[i]==0)
        for(j=i*i;j<=100000;j+=i*2)
        {
            if(j%i==0)vis[j]=1;
        }
    }

    for(i=4;i<=100000;i+=2)
        vis[i]=1;
    sn("%d",&t);
    while(t--)
    {
        sn("%d",&n);
        printf("Case %d: %.9lf\n",cs++,rec(n));
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

