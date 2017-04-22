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
int tree[3*1500000],id[3*1500000],ar[1500000];

void build(int p,int l,int r)
{
    if(l==r)
    {
        id[l]=p;
        tree[p]=1;
        return;
    }
    int mid=(l+r)/2;
    build(2*p,l,mid);
    build(2*p+1,mid+1,r);
    tree[p]=tree[2*p]+tree[2*p+1];
}
void query(int p,int l,int r,int x)
{
    if(x<=0)return;
    if(l==r)
    {
        tree[p]=0;
        return;
    }
    int mid=(l+r)/2;
    if(tree[2*p]>=x)
    query(2*p,l,mid,x);
    else
     query(2*p+1,mid+1,r,x-tree[2*p]);
    tree[p]=tree[2*p]+tree[2*p+1];
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
  #ifdef O_judge
    //freopen(".txt","r",stdin);
  #endif
    memset(tree,0,sizeof(tree));
    for(i=1,n=0,j=1;i<=1429431;i+=2,j++)
    {
        if(j%3!=0)
         ar[n++]=i;
    }
    build(1,0,n-1);
    for(i=2,m=2;i<n;i++)
    {
        if(tree[id[i]]==1)
        {
            //pf("%d ",ar[i]);
            ar[m++]=ar[i];
            u=tree[1]/ar[i];
            for(j=1;j<=u;j++)
            {
                query(1,0,n-1,(ar[i]*j)-j+1);
            }
        }
    }
    sn("%d",&t);
    while(t--)
    {
        sn("%d",&n);
        pf("Case %d: %d\n",cs++,ar[n-1]);
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

