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
int ar[505][505],n,m,arr[505][505],dp[505][505];

int rec(int p,int l)
{
    if(p>=n)
        return 0;
    int &ret=dp[p][l];
    if(ret!=-1)
        return ret;
    ret=0;
    int s=0;
    for(int i=l;i<=m;i++)
    {
       if(i==0)
            s=arr[p][i];
       else if(i>0&&i<m)
          s=ar[p][i-1]+arr[p][i];
       else if(i==m)
           s=ar[p][i-1];
       ret=max(ret,rec(p+1,i)+s);
    }

return ret;
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,a,b,c,d,e,f,g,h,u,v;
  #ifdef O_judge
    freopen("Output.txt","r",stdin);
  #endif
    sn("%d",&t);
    while(t--)
    {
        sn("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                sn("%d",&ar[i][j]);
            }
        }
         for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                sn("%d",&arr[i][j]);
            }
        }
         for(i=0;i<n;i++)
        {
            for(j=1;j<m;j++)
            {
                ar[i][j]+=ar[i][j-1];
            }
        }
         for(i=0;i<n;i++)
        {
            for(j=m-2;j>=0;j--)
            {
                arr[i][j]+=arr[i][j+1];
            }
        }
        memset(dp,-1,sizeof(dp));
        pf("Case %d: %d\n",cs++,rec(0,0));
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

