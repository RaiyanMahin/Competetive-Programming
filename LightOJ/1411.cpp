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
int maxv=250000;
using namespace std;
struct T{
ll a,b,c,s,nxt;
}tr[1000006];
void update(ll p,ll l,ll r,ll x,ll y,ll ty,ll v)
{
    if(l>y||r<x)
        return;
    ll mid=(l+r)/2;
    if(l!=r)
    {
        if(tr[p].nxt==0)
        {
            tr[2*p].a=tr[2*p].b=tr[2*p].c=tr[2*p].s=0;
            tr[2*p+1].a=tr[2*p+1].b=tr[2*p+1].c=tr[2*p+1].s=0;
        }
        tr[2*p].a=(tr[2*p].a+tr[p].a);
        tr[2*p+1].a=(tr[2*p+1].a+tr[p].a);
        tr[2*p].b=(tr[2*p].b+tr[p].b);
        tr[2*p+1].b=(tr[2*p+1].b+tr[p].b);
        tr[2*p].c=(tr[p].c+tr[2*p].c+(r-mid)*tr[p].b);
        tr[2*p+1].c=(tr[p].c+tr[2*p+1].c+(mid+1-l)*tr[p].a);
        if(tr[p].a>0)
        {
            tr[2*p].s+=(tr[p].a*(mid-l+1)*(mid-l+2))/2;
            tr[2*p+1].s+=(tr[p].a*(r-mid)*(r-mid+1))/2;
            tr[2*p+1].s+=(tr[p].a*(mid-l+1)*(r-mid));
        }
        if(tr[p].b>0)
        {
            tr[2*p].s+=(tr[p].b*(mid-l+1)*(mid-l+2))/2;
            tr[2*p+1].s+=(tr[p].b*(r-mid)*(r-mid+1))/2;
            tr[2*p].s+=(tr[p].b*(mid-l+1)*(r-mid));
        }
        tr[2*p].s+=(mid-l+1)*tr[p].c;
        tr[2*p+1].s+=(r-mid)*tr[p].c;
        tr[2*p].nxt&=tr[p].nxt;
        tr[2*p+1].nxt&=tr[p].nxt;
        tr[p].nxt=1;tr[p].a=0;tr[p].b=0;tr[p].c=0;
    }
    if(l>=x&&r<=y)
    {
        if(ty==1)
        {
            tr[p].a++;
            tr[p].s+=((r-l+1)*(r-l+2))/2;
            tr[p].s+=((r-l+1)*(l-x));
            tr[p].c+=(l-x);
        }
        if(ty==2)
        {
            tr[p].b++;
            tr[p].s+=((r-l+1)*(r-l+2))/2;
            tr[p].s+=((r-l+1)*(y-r));
            tr[p].c+=(y-r);
        }
        if(ty==3)
        {
            tr[p].a=tr[p].b=0;
            tr[p].c=v;
            tr[p].s=v*(r-l+1);
            tr[p].nxt=0;
        }
        return;
    }
    update(2*p,l,mid,x,y,ty,v);
    update(2*p+1,mid+1,r,x,y,ty,v);
    tr[p].s=tr[2*p].s+tr[2*p+1].s;
}
ll query(ll p,ll l,ll r,ll x,ll y)
{
    if(l>y||r<x)
        return 0;
    ll mid=(l+r)/2;
  if(l!=r)
    {
        if(tr[p].nxt==0)
        {
            tr[2*p].a=tr[2*p].b=tr[2*p].c=tr[2*p].s=0;
            tr[2*p+1].a=tr[2*p+1].b=tr[2*p+1].c=tr[2*p+1].s=0;
        }
        tr[2*p].a=(tr[2*p].a+tr[p].a);
        tr[2*p+1].a=(tr[2*p+1].a+tr[p].a);
        tr[2*p].b=(tr[2*p].b+tr[p].b);
        tr[2*p+1].b=(tr[2*p+1].b+tr[p].b);
        tr[2*p].c=(tr[p].c+tr[2*p].c+(r-mid)*tr[p].b);
        tr[2*p+1].c=(tr[p].c+tr[2*p+1].c+(mid+1-l)*tr[p].a);
        if(tr[p].a>0)
        {
            tr[2*p].s+=(tr[p].a*(mid-l+1)*(mid-l+2))/2;
            tr[2*p+1].s+=(tr[p].a*(r-mid)*(r-mid+1))/2;
            tr[2*p+1].s+=(tr[p].a*(mid-l+1)*(r-mid));
        }
        if(tr[p].b>0)
        {
            tr[2*p].s+=(tr[p].b*(mid-l+1)*(mid-l+2))/2;
            tr[2*p+1].s+=(tr[p].b*(r-mid)*(r-mid+1))/2;
            tr[2*p].s+=(tr[p].b*(mid-l+1)*(r-mid));
        }
        tr[2*p].s+=(mid-l+1)*tr[p].c;
        tr[2*p+1].s+=(r-mid)*tr[p].c;
        tr[2*p].nxt&=tr[p].nxt;
        tr[2*p+1].nxt&=tr[p].nxt;
        tr[p].nxt=1;tr[p].a=0;tr[p].b=0;tr[p].c=0;
    }
    if(l>=x&&r<=y)
    {
        return tr[p].s;
    }
     ll a=query(2*p,l,mid,x,y);
    a+=query(2*p+1,mid+1,r,x,y);
    tr[p].s=tr[2*p].s+tr[2*p+1].s;
    return a;
}
int main()
{
    int i,j,k,l,t,cs=1,r=1,s,m,n,a,b,c,d,e,f,g,h,u,v;

    //freopen(".txt","r",stdin);
    sn("%d",&t);
    while(t--)
    {
        sn("%d",&n);
        memset(tr,0,sizeof(tr));
        pf("Case %d:\n",cs++);
        while(n--)
        {
            char st[4];
            sn("%s %d %d",&st,&u,&v);
            u--;v--;
            if(st[0]=='A')
            {
                update(1,0,maxv-1,u,v,1,0);
            }
            if(st[0]=='B')
            {
                update(1,0,maxv-1,u,v,2,0);
            }
            if(st[0]=='C')
            {
                sn("%d",&c);
                update(1,0,maxv-1,u,v,3,c);
            }
            if(st[0]=='S')
            {
                //update(1,0,maxv-1,u,v,1,0);
                pf("%lld\n",query(1,0,maxv-1,u,v));
            }
        }
    }
    return 0;

}

/*
#include <bits/stdc++.h>
  #define _ ios_base::sync_with_stdio(0);cin.tie(0);
*/

