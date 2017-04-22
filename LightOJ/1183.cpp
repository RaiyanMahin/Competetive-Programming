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
int a,s,c;
}tr[500000];
int ar[100005];
void build(int p,int l,int r)
{
    if(l==r)
    {
        tr[p].a=1;
        tr[p].s=0;
        tr[p].c=0;
        return;
    }
    int mid=(l+r)/2;
    build(2*p,l,mid);
    build(2*p+1,mid+1,r);
    tr[p].a=1;tr[p].s=0;
    tr[p].a=1;tr[p].c=0;
}
void update(int p,int l,int r,int x,int y,int v)
{
    if(l>y||r<x)
        return;
    int mid=(l+r)/2;
    if(l!=r)
    {
       if(tr[p].a==0)
       {
           tr[2*p].s=0;
           tr[2*p].c=0;
           tr[2*p+1].s=0;
           tr[2*p+1].c=0;
           tr[2*p].a&=tr[p].a;
           tr[2*p+1].a&=tr[p].a;
           tr[2*p+1].c=tr[p].c;
           tr[2*p].c=tr[p].c;
           tr[2*p].s=tr[p].c*(mid-l+1);
           tr[2*p+1].s=tr[p].c*(r-mid);
       }
       tr[p].a=1;
    }
    if(l>=x&&r<=y)
    {
        tr[p].a=0;
        tr[p].c=v;
        tr[p].s=(r-l+1)*v;
        return;
    }
    update(2*p,l,mid,x,y,v);
    update(2*p+1,mid+1,r,x,y,v);
    tr[p].s=tr[2*p].s+tr[2*p+1].s;
}
int query(int p,int l,int r,int x,int y)
{
    if(l>y||r<x)
        return 0;
    int mid=(l+r)/2;
        if(l!=r)
    {
       if(tr[p].a==0)
       {
           tr[2*p].s=0;
           tr[2*p].c=0;
           tr[2*p+1].s=0;
           tr[2*p+1].c=0;
           tr[2*p].a&=tr[p].a;
           tr[2*p+1].a&=tr[p].a;
           tr[2*p+1].c=tr[p].c;
           tr[2*p].c=tr[p].c;
           tr[2*p].s=tr[p].c*(mid-l+1);
           tr[2*p+1].s=tr[p].c*(r-mid);
       }
       tr[p].a=1;
    }
    if(l>=x&&r<=y)
    {
        return tr[p].s;
    }
    int a=query(2*p,l,mid,x,y);
    a+=query(2*p+1,mid+1,r,x,y);
    tr[p].s=tr[2*p].s+tr[2*p+1].s;
    return a;
}
int gcd(int a,int b)
{
    if(a%b==0)
        return b;
    else return gcd(b,a%b);
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%d",&t);
    while(t--)
    {
        sn("%d %d",&n,&d);
        build(1,0,n-1);
        int ans=0;
        pf("Case %d:\n",cs++);
        for(i=0;i<d;i++)
        {
            sn("%d %d %d",&h,&u,&v);
            if(h==1)
            {
                sn("%d",&c);
                update(1,0,n-1,u,v,c);
            }
            else
            {
                a=query(1,0,n-1,u,v);
               // pf("--%d\n",a);
                b=v-u+1;
                c=gcd(a,b);
                a/=c;
                b/=c;
                if(b==1)
                    pf("%d\n",a);
                else
                    pf("%d/%d\n",a,b);
            }
        }
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/


