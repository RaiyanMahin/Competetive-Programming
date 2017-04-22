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
struct T{
ll a,s[11];
}tr[500000];
struct TT{
int y,x1,x2,v;
   TT(int _y=0,int _x1=0,int _x2=0,int _v=0)
   {
       y=_y;x1=_x1;x2=_x2;v=_v;
   }
}ar[100000];
ll X[100000],K;
bool cmp(TT x,TT y)
{
    return x.y<y.y;
}
void build(int p,int l,int r)
{
    if(l==r)
    {
        tr[p].a=0;
        memset(tr[p].s,0,sizeof(tr[p].s));
        tr[p].s[0]=X[r]-X[l-1];
        return;
    }
    int mid=(l+r)/2,i;
    build(2*p,l,mid);
    build(2*p+1,mid+1,r);
    memset(tr[p].s,0,sizeof(tr[p].s));
    tr[p].a=0;
    for(i=0;i<11;i++)
        tr[p].s[i]=tr[2*p].s[i]+tr[2*p+1].s[i];
}
void update(int p,int l,int r,int x,int y,int v)
{
    if(l>y||r<x)
        return;
    int i;
    if(l>=x&&r<=y)
    {
        tr[p].a+=v;
        memset(tr[p].s,0,sizeof(tr[p].s));
        if(l==r)
        {
            if(tr[p].a<K)
                tr[p].s[tr[p].a]=X[r]-X[l-1];
        }
        else
        {
            for(i=0;i+tr[p].a<K;i++)
            {
                tr[p].s[i+tr[p].a]=tr[2*p].s[i]+tr[2*p+1].s[i];
            }
        }
        return;
    }
    int mid=(l+r)/2;
    update(2*p,l,mid,x,y,v);
    update(2*p+1,mid+1,r,x,y,v);
    memset(tr[p].s,0,sizeof(tr[p].s));
     for(i=0;i+tr[p].a<K;i++)
            {
                tr[p].s[i+tr[p].a]=tr[2*p].s[i]+tr[2*p+1].s[i];
            }
}
int fnd(int u,int n)
{
    int lw=0,hi=n-1,mid;
    while(lw<=hi)
    {
        mid=(lw+hi)/2;
        if(X[mid]==u)
            return mid;
        else if(X[mid]<u)
            lw=mid+1;
        else
            hi=mid-1;
    }
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%d",&t);
    while(t--)
    {
        sn("%d %lld",&n,&K);
        m=0;f=0;
        for(i=0;i<n;i++)
        {
            sn("%d %d %d %d",&a,&b,&c,&d);
            a++,c++;
            X[f++]=a;
            X[f++]=a-1;
            X[f++]=c;
            ar[m++]=TT(b,a,c,1);
            ar[m++]=TT(d+1,a,c,-1);
        }
        sort(X,X+f);
        c=1;
        for(i=c=1;i<f;i++)
        {
            if(X[c-1]!=X[i])
            {
                X[c++]=X[i];
            }
        }
        sort(ar,ar+m,cmp);
        build(1,1,c-1);
        ll ans=0,sum;
        for(i=0;i<m-1;i++)
        {
            u=fnd(ar[i].x1,c);
            v=fnd(ar[i].x2,c);
            if(u<=v)
            update(1,1,c-1,u,v,ar[i].v);
            sum=X[c-1]-X[0];
            for(j=0;j<K;j++)
                sum-=tr[1].s[j];
             ans=ans+abs(ar[i+1].y-ar[i].y)*sum;
        }
        pf("Case %d: %lld\n",cs++,ans);
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

