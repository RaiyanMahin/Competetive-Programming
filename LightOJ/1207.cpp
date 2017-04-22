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
int tree[600005];

void query(int p,int l,int r,int x,int y,int z)
{
    if(l>y||r<x)
    {
        return ;
    }
    if(l>=x&&r<=y)
    {
        tree[p]=z;
        return;
    }
    int mid=(l+r)/2;
    query(2*p,l,mid,x,y,z);
    query(2*p+1,mid+1,r,x,y,z);
}
int id[600005];
void build(int p,int l,int r)
{
    if(l==r)
    {
        id[l]=p;
        tree[p]=0;
        return;
    }
    int mid=(l+r)/2;
    build(2*p,l,mid);
    build(2*p+1,mid+1,r);
    tree[p]=tree[2*p]+tree[2*p+1];
}
int vis[100005];
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
  #ifdef O_judge
    //freopen(".txt","r",stdin);
  #endif
     sn("%d",&t);
     while(t--)
     {
         sn("%d",&n);
         memset(tree,0,sizeof(tree));
         memset(vis,0,sizeof(vis));
         build(1,0,2*n);
         for(i=0;i<n;i++)
         {
             sn("%d %d",&u,&v);
             query(1,0,2*n,u-1,v-1,i+1);
         }
         int ans=0;vis[0]=1;
         for(i=0;i<2*n;i++)
         {
             u=id[i];s=0;
              while(u>0)
              {
                  if(tree[u]>s)s=tree[u];
                  u=u/2;
              }
             if(vis[s]==0)
             {
                 ans++;vis[s]=1;
             }
         }
         pf("Case %d: %d\n",cs++,ans);
     }
    return 0;
}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

