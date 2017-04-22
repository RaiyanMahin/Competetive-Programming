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
ll a,b;
}ar[200005];

int tr[500000];

void build(int p,int l,int r)
{
    if(l==r)
    {
        tr[p]=ar[l].b;
        return;
    }
    int mid=(l+r)/2;

    build(2*p,l,mid);
    build(2*p+1,mid+1,r);
    tr[p]=max(tr[2*p],tr[2*p +1]);
}
int  query(int p,int l,int r,int x,int y)
{
    if(l>y||r<x)
    {
        //tr[p]=ar[l].a;
        return 0;
    }
    if(l>=x&&r<=y)
    {
        return tr[p];
    }
    int mid=(l+r)/2;

    return max(query(2*p,l,mid,x,y),query(2*p+1,mid+1,r,x,y));
}
ll dp[200005],lw[200005],vis[200005],hi[200005];
int main()
{
    ll i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%lld",&t);
    while(t--)
    {
        sn("%lld",&n);
        for(i=0;i<n;i++)
        {
            sn("%lld %lld",&ar[i].a,&ar[i].b);
        }
       // build(1,0,n-1);
        memset(vis,0,sizeof(vis));
        lw[n+1]=n;
        for(i=n,j=n;i>=1;i--)
        {
            lw[i]=lw[i+1];
           for(;j>=1;j--)
           {
               if(vis[ar[j-1].a]==0)
               {
                   lw[i]=j;
                   vis[ar[j-1].a]++;
               }
               else
               {
                   break;
               }
           }
           vis[ar[i-1].a]--;
        }
        for(i=1;i<=n;i++)
        {
            vis[i]=i;
            for(j=i;j>0;j=vis[j]-1)
            {
                if(ar[i-1].b>=ar[j-1].b)
                    vis[i]=vis[j];
            }
        }
        dp[0]=0;
        for(i=1;i<=n;i++)
        {
            vis[i]=max(vis[i],lw[i]);
            dp[i]=1LL<<62LL;
            for(j=i;j>=lw[i];j=vis[j]-1)
            {
                u=max(lw[i],vis[j]);
                dp[i]=min(dp[i],dp[u-1]+ar[j-1].b);
            }
        }
        pf("Case %lld: %lld\n",cs++,dp[n]);
    }

    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

