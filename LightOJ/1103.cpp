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
int a,b,c;
}ar[200005];
int bit[200005];
bool cmp(T x, T y)
{
    if(x.b==y.b)
        return x.c<y.c;
        return x.b<y.b;
}

void update(int x,int mx)
{
    while(x<mx)
    {
        bit[x]++;
        x+=x&-x;
    }
}

int query(int x)
{
    int s=0;
    while(x>0)
    {
        s=s+bit[x];
        x-=x&-x;
    }
    return s;
}
int main()
{
   ll i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;
  #ifdef O_judge
    //freopen(".txt","r",stdin);
  #endif
  sn("%lld",&t);
  while(t--)
  {
      sn("%lld %lld",&n,&m);
      for(i=0;i<n+m;i++)
      {
          sn("%lld %lld",&ar[i].a,&ar[i].b);
          if(i<n)ar[i].c=1;
          else ar[i].c=2;
      }
      sort(ar,ar+m,cmp);
      ll ans=0;
      memset(bit,0,sizeof(bit));
      u=0;
      for(i=0;i<n+m;i++)
      {
          if(ar[i].c==1)
          {
              update(ar[i].a,n+m);u++;
          }
          else
          {
              v=query(ar[i].a);
              ans=ans+(u-v);
          }
      }
    //  sort(ar,ar+m,cmp);
      memset(bit,0,sizeof(bit));
      u=0;
      for(i=m+n-1;i>=0;i--)
      {
          if(ar[i].c==2)
          {
              update(ar[i].a+1,n+m);
          }
          else
          {
              v=query(ar[i].a);
              ans=ans+v;
          }
      }
      pf("Case %lld: %lld\n",cs++,ans);
  }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

