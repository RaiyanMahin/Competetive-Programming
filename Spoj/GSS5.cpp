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
#define mp make_pair



typedef long long int ll;
using namespace std;
struct T{
int sum,l,r,a;
}tr[100000];
int ar[20000];
void build_all(int p,int l,int r)
{
    if(l==r)
    {
        tr[p].sum=tr[p].a=tr[p].l=tr[p].r=ar[l];
        return;
    }
    int mid=(l+r)/2;
    build_all(2*p,l,mid);
    build_all(2*p+1,mid+1,r);

    tr[p].sum=tr[2*p].sum+tr[2*p+1].sum;

    tr[p].l=max(tr[2*p].l,tr[2*p].sum+tr[2*p+1].l);
    tr[p].l=max(tr[p].l,tr[p].sum);

    tr[p].r=max(tr[2*p+1].r,tr[2*p+1].sum+tr[2*p].r);
    tr[p].r=max(tr[p].r,tr[p].sum);

    tr[p].a=max(tr[2*p].a,tr[2*p+1].a);
    tr[p].a=max(tr[p].a,tr[p].l);
    tr[p].a=max(tr[p].a,tr[p].r);
    tr[p].a=max(tr[p].a,tr[p].sum);
    tr[p].a=max(tr[p].a,tr[2*p].r+tr[2*p+1].l);
}

T query(int p,int l,int r,int x,int y)
{
   if(y<x)
   {
       T tm;
       tm.l=tm.a=tm.r=tm.sum=0;
       return tm;
   }
   if(l>=x&&r<=y)
   {
       return tr[p];
   }

   int mid=(l+r)/2;
   if(y<=mid)
   {
       return query(2*p,l,mid,x,y);
   }
   else if(x>mid)
   {
       return query(2*p+1,mid+1,r,x,y);
   }
   else
   {
       T tm1=query(2*p,l,mid,x,y);
       T tm2=query(2*p+1,mid+1,r,x,y);
       T tm;
       tm.sum=tm1.sum+tm2.sum;

       tm.l=max(tm1.l,tm1.sum+tm2.l);
       tm.l=max(tm.l,tm.sum);

       tm.r=max(tm2.r,tm2.sum+tm1.r);
       tm.r=max(tm.r,tm.sum);

       tm.a=max(tm1.a,tm2.a);
       tm.a=max(tm.a,tm.l);
       tm.a=max(tm.a,tm.r);
       tm.a=max(tm.a,tm.sum);
       tm.a=max(tm.a,tm1.r+tm2.l);
       return tm;
   }
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%d",&t);
    while(t--)
    {
        sn("%d",&n);
        for(i=0;i<n;i++)
        {
            sn("%d",&ar[i]);
        }
        build_all(1,0,n-1);
        int q;
        sn("%d",&q);
        for(i=0;i<q;i++)
        {
            sn("%d %d %d %d",&a,&b,&c,&d);
            a--;b--;c--;d--;
            int ans=0;
            if(c<=b)
            {
               ans=query(1,0,n-1,c,b).a;
               ans=max(ans,query(1,0,n-1,a,b).r+query(1,0,n-1,b+1,d).l);
               ans=max(ans,query(1,0,n-1,a,c-1).r+query(1,0,n-1,c,d).l);
            }
            else
            {
                ans=query(1,0,n-1,a,b).r+query(1,0,n-1,b+1,c-1).sum+query(1,0,n-1,c,d).l;
            }
            pf("%d\n",ans);
        }
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

