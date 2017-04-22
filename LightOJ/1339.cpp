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
int tr[3*100005],ar[100005],arr[100005],pn[100005],pr[100005];

void build(int p,int l,int r)
{
    if(l==r)
    {
        tr[p]=pn[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*p,l,mid);
    build(2*p+1,mid+1,r);
    tr[p]=max(tr[2*p],tr[2*p+1]);
}

int query(int p,int l,int r,int x,int y)
{
    if(l>y|r<x)
        return 0;
    if(l>=x&&r<=y)
    {
        return tr[p];
    }
    int mid=(l+r)/2;
    return max(query(2*p,l,mid,x,y),query(2*p+1,mid+1,r,x,y));
}

int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v,q;
  #ifdef O_judge
    //freopen(".txt","r",stdin);
  #endif
  sn("%d",&t);
  while(t--)
  {
      sn("%d %d %d",&n,&c,&q);
      for(i=j=0;i<n;i++)
      {
          sn("%d",&ar[i]);
          if(i==0)
          {
              arr[j]=0;pr[ar[i]]=0;
          }
          else if(ar[i]!=ar[i-1])
            arr[++j]=i,pr[ar[i]]=j;

      }
       arr[++j]=n;
       for(i=0;i<j;i++)
       {
          pn[i]=arr[i+1]-arr[i];
       }
       m=j;
       build(1,0,m-1);
       pf("Case %d:\n",cs++);
       while(q--)
       {
           sn("%d %d",&u,&v);u--,v--;
           int ans;
           ans=min(v+1,arr[pr[ar[u]]]+pn[pr[ar[u]]])-u;
           ans=max(ans,(1+v-max(arr[pr[ar[v]]],u)));
           ans=max(ans,query(1,0,m-1,pr[ar[u]]+1,pr[ar[v]]-1));
           pf("%d\n",ans);
       }

  }

    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

