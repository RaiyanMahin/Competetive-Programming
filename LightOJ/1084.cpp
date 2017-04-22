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

const double PI=2.0*acos(0);

typedef long long int ll;
using namespace std;
int tr[400000],id[400000];
void build(int p,int l,int r)
{
    if(l==r)
    {
        tr[p]=100000000;
        id[l]=p;
        return ;
    }
    int mid=(l+r)/2;
    build(2*p,l,mid);
    build(2*p+1,mid+1,r);
    tr[p]=100000000;
}
void update(int p,int v)
{
    while(p>0)
    {
        tr[p]=min(tr[p],v);
        p/=2;
    }
}
int query(int p,int l,int r,int x,int y)
{
    if(l>y||r<x)
        return 100000000;
    if(l>=x&&r<=y)
    {
        return tr[p];
    }
    int mid=(l+r)/2;
    return min(query(2*p,l,mid,x,y),query(2*p+1,mid+1,r,x,y));
}
int ar[1000000],vis[150000];
int fnd_l(int u,int s,int n)
{
    int lw=s,hi=n-1,mid;
    while(lw<=hi)
    {
        mid=(lw+hi)/2;
        if(ar[mid]>=u)
        {
            if(mid-1>=s&&ar[mid-1]>=u)
                hi=mid-1;
            else return mid;
        }
        else
            lw=mid+1;
    }
}
int fnd_u(int u,int s,int n)
{
    int lw=s,hi=n-1,mid;
    while(lw<=hi)
    {
        mid=(lw+hi)/2;
        if(ar[mid]<=u)
        {
            if(mid+1<n&&ar[mid+1]<=u)
                lw=mid+1;
            else return mid;
        }
        else
            hi=mid-1;
    }
}

int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    sn("%d",&t);
    while(t--)
    {
        sn("%d %d",&n,&d);
        for(i=0;i<n;i++)
            sn("%d",&ar[i]);
        sort(ar,ar+n);
        s=0;
        build(1,0,n);
        update(id[0],0);
        v=100000000;
        for(i=2;i<n;i++)
        {
            u=fnd_l(ar[i]-2*d,0,i+1);
            if(u<=i-2)
            {
                 v=query(1,0,n,u,i-2)+1;
                 update(id[i+1],v);
            }
            else v=100000000;
        }
        if(v>(n/2)||s==-1)
            v=-1;
        pf("Case %d: %d\n",cs++,v);
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

